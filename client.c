//client code for Windows(9b_Windows_system.c)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib") // Link with ws2_32.lib

#define PORT 8080

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char *message = "Hello from client", server_reply[1024];
    int recv_size;

    printf("Initializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    printf("Winsock initialized.\n");

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d\n", WSAGetLastError());
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connect failed with error code: %d\n", WSAGetLastError());
        return 1;
    }

    printf("Connected to server.\n");

    // Send data
    send(sock, message, strlen(message), 0);
    printf("Message sent.\n");

    // Receive response
    if ((recv_size = recv(sock, server_reply, sizeof(server_reply), 0)) == SOCKET_ERROR) {
        printf("Recv failed\n");
        return 1;
    }

    server_reply[recv_size] = '\0';
    printf("Server reply: %s\n", server_reply);

    closesocket(sock);
    WSACleanup();

    return 0;
}
// Compile with:
// gcc server.c -o server.exe -lws2_32
// gcc client.c -o client.exe -lws2_32
// Run server first, then client
//run client in a separate terminal
//.\client.exe


//sample output

// Initializing Winsock...
// Winsock initialized.
// Connected to server.
// Message sent.
// Server reply: Hello from server


