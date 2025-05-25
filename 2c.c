//lrc code
#include <stdio.h>

int main() {
  int i;
  int data[100], lrc = 0, num_bits;

  printf("Enter the number of bits: ");
  scanf("%d", &num_bits);

  printf("Enter the binary data (bit by bit at a time):\n");
  // Read the binary data
  for (i = 0; i < num_bits; i++) {
    scanf("%d", &data[i]);
  }

  // compute the LRC
  for (i = 0; i < num_bits; i++) {
    lrc ^= data[i];
  }

  // print the LRC and the original data
  printf("\nThe LRC is: %d\n", lrc);
  printf("The Original data (in binary format) is: ");
  for (i = 0; i < num_bits; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");

  return 0;
}
//sample output
/*
Enter the no of bits: 3
Enter the binary data (one bit at a time):
1
0
0
The lrc is: 1
The original data (in binary format) is: 1 0 0

Enter the no of bits: 4
Enter the binary data (one bit at a time):
1
0
1
0
1
0
0
1
The lrc is: 0
The original data (in binary format) is: 1 0 1 0 1 0 0 1
*/