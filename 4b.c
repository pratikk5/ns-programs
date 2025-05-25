//slelctive repeater protocol
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WINDOW_SIZE 4
#define FRAME_COUNT 10

typedef struct {
  int seq_num;
  int sent;
  int ack;
} Frame;

Frame frames[FRAME_COUNT];

int main() {
  int base = 0, next_seq_num = 0;

  for (int i = 0; i < FRAME_COUNT; i++) {
    frames[i].sent = 0;
    frames[i].ack = 0;
    frames[i].seq_num = i;
  }

  while (base < FRAME_COUNT) {
    while (next_seq_num < base + WINDOW_SIZE && next_seq_num < FRAME_COUNT) {
      if (!frames[next_seq_num].sent) {
        printf("Sending frame %d\n", frames[next_seq_num].seq_num);
        frames[next_seq_num].sent = 1;
      }
      next_seq_num++;
    }

    for (int i = base; i < base + WINDOW_SIZE && i < FRAME_COUNT; i++) {
      if (!frames[i].ack) {
        printf("Acknowledgement received for frame %d\n", frames[i].seq_num);
        frames[i].ack = 1;
      }
    }

    while (base < FRAME_COUNT && frames[base].ack) {
      base++;
    }

    if (next_seq_num < FRAME_COUNT && !frames[next_seq_num].sent) {
      printf("Timeout for frame %d, resending\n", frames[next_seq_num].seq_num);
      frames[next_seq_num].sent = 0;
    }
  }

  printf("All frames successfully transmitted and acknowledged\n");

  getch();
  return 0;
}
/*
Sending frame 0
Sending frame 1
Sending frame 2
Sending frame 3
Acknowledgement received for frame 0
Acknowledgement received for frame 1
Acknowledgement received for frame 2
Acknowledgement received for frame 3
Sending frame 4
Sending frame 5
Sending frame 6
Sending frame 7
Acknowledgement received for frame 4
Acknowledgement received for frame 5
Acknowledgement received for frame 6
Acknowledgement received for frame 7
Sending frame 8
Sending frame 9
Acknowledgement received for frame 8
Acknowledgement received for frame 9
All frames successfully transmitted and acknowledged
*/