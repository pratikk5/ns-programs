#include <stdio.h>
#include <conio.h>
int main() {
  int frame_size, sent = 0, ack, i;

  printf("Enter the number of frames: ");
  scanf("%d", &frame_size);

  while (1) {
    for (i = 0; i < frame_size; i++) {
      printf("Frame %d has been transmitted.\n", sent);
      sent++;
      if (sent == frame_size) {
        break;
      }
    }
    if (sent == frame_size) {
      break;
    }
    printf("In please enter the last acknowledgement received (0 to %d): ", frame_size - 1);
    scanf("%d", &ack);
    if (ack >= frame_size) {
      break;
    } else {
      sent = ack + 1;
    }
  }
  getch();
  return 0;
}
//sample output
/*
Enter the number of frames: 3
Frame 0 has been transmitted.
Frame 1 has been transmitted.
Frame 2 has been transmitted.
*/