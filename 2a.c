//Hamming code 
#include <stdio.h>
#include <conio.h>

void main() {
  int data[7], rec[7], i, c1, c2, c3, c;
  printf("This works for message of 4 bits. Enter message bit one by one:");
  scanf("%d %d %d %d", &data[0], &data[1], &data[2], &data[4]);

  data[6] = data[0] ^ data[2] ^ data[4];
  data[5] = data[0] ^ data[1] ^ data[4];
  data[3] = data[0] ^ data[1] ^ data[2];
  printf("\nIn the encoded bits are given below:\n");
  for (i = 0; i < 7; i++) {
    printf("%d ", data[i]);
  }
  printf("\n\nEnter the received data bits one by one:");
  for (i = 0; i < 7; i++) {
    scanf("%d", &rec[i]);
  }
  c1 = rec[6] ^ rec[4] ^ rec[2] ^ rec[0];
  c2 = rec[5] ^ rec[4] ^ rec[1] ^ rec[0];
  c3 = rec[3] ^ rec[2] ^ rec[1] ^ rec[0];
  c = c3 * 4 + c2 * 2 + c1;
  if (c == 0) {
    printf("\nCongratulations there is no error:");
  } else {
    printf("\nError on the position: %d \nCorrect message is:\n", c);
    if (rec[7 - c] == 0) {
      rec[7 - c] = 1;
    } else {
      rec[7 - c] = 0;
    }
  }
  for (i = 0; i < 7; i++) {
    printf("%d ", rec[i]);
  }
  getch();
}
//sample output
/*
This works for message of 4 bits in size

enter message bit one by one: 1 0 1 0

the encoded bits are given below:
1 0 1 0 0 1 0

Enter the received data bits one by one: 1 0 1 0 0 1 0

Congratulations there is no error: 1 0 1 0 0 1 0

*/
/*

This works for message of 4 bits in size
enter message bit one by one: 1 0 1 0

the encoded bits are given below:
1 0 1 0 0 1 0

Enter the received data bits one by one: 0 1 0 0 1 0

Error on the position: 7
Correct message is:
1 0 1 0 0 1 1

*/