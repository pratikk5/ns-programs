#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For malloc and free
#include <conio.h>

int main() {
  int window_size, i;
  char *sender, *receiver;

  printf("Enter the window size: ");
  scanf("%d", &window_size);

  printf("In Sender window size is expanded to store message or window.\n");
  printf("Enter the data to be sent: ");
  fflush(stdin); // Clear input buffer
  sender = (char *)malloc(sizeof(char) * (window_size + 1));
  gets(sender);

  receiver = (char *)malloc(sizeof(char) * (window_size + 1));
  for (i = 0; i < window_size; i++) {
    receiver[i] = sender[i];
  }
  receiver[window_size] = '\0';

  printf("\nMessage SENT BY THE SENDER: \n");
  puts(sender);

  printf("\nWINDOW SIZE OF THE RECEIVER IS EXPANDED.\n");
  printf("\nACKNOWLEDGEMENT FROM RECEIVER\n");
  for (i = 0; i < window_size; i++) {
    printf("In ACK: %d\n", i);
  }

  printf("\nMessage Received by Receiver is: \n");
  puts(receiver);

  printf("\nWindow Size of receiver is shrinked.\n");

  free(sender);
  free(receiver);

  getch();

  return 0;
}
//sample output
/*Enter the window size: 4
In Sender window size is expanded to store message or window.
Enter the data to be sent: Hello

Message SENT BY THE SENDER:
Hello

WINDOW SIZE OF THE RECEIVER IS EXPANDED.

ACKNOWLEDGEMENT FROM RECEIVER
In ACK: 0
In ACK: 1
In ACK: 2
In ACK: 3

Message Received by Receiver is:
Hell

Window Size of receiver is shrinked.
*/