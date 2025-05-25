//Go back N protocol
#include <stdio.h>

int main() {
  int window_size, sent = 0, ack, i;

  printf("Enter window size: ");
  scanf("%d", &window_size);

  while (1) {
    for (i = 0; i < window_size; i++) {
      printf("Frame %d has been transmitted\n", sent++);
      if (sent == window_size)
        break;
    }

    printf("In plane Enter the last acknowledgement Received\n");
    scanf("%d", &ack);

    if (ack == window_size)
      break;
    else
      sent = ack;
  }
  return 0;
}
//sample output
/*
Enter window size: 4
Frame 0 has been transmitted
Frame 1 has been transmitted
Frame 2 has been transmitted
Frame 3 has been transmitted
In plane Enter the last acknowledgement Received
3
Frame 3 has been transmitted
In plane Enter the last acknowledgement Received
4
*/