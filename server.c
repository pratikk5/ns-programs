//server code for windows(9a_windows_system.c)
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link with ws2_32.lib

#define PORT 8080

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in server, client;
    int c;
    char *message;
    char buffer[1024] = {0};
    int valread;

    printf("Initializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    // Create socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if(bind(server_fd, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Listen
    listen(server_fd, 3);
    printf("Waiting for incoming connections...\n");

    c = sizeof(struct sockaddr_in);
    new_socket = accept(server_fd, (struct sockaddr *)&client, &c);
    if (new_socket == INVALID_SOCKET) {
        printf("accept failed with error code : %d", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Receive message
    valread = recv(new_socket, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);

    // Reply
    message = "Hello from server";
    send(new_socket, message, strlen(message), 0);
    printf("Message sent\n");

    closesocket(server_fd);
    WSACleanup();

    return 0;
}

//note file names must be server.c  and client.c respectively


/* Run the commands in the terminal to compile and run the code: 
gcc server.c -o server.exe -lws2_32
gcc client.c -o client.exe -lws2_32
run the server first and then the client in another terminal
//run the server in terminal 1
.\server.exe
*/



//sample output


// Initializing Winsock...
// Waiting for incoming connections...
// Received: Hello from client
// Message sent