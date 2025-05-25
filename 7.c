//Data encryption and decryption using DSA
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main() {
  static int s, i, k, n, c[100];
  printf("In program 1. Encryption and decryption\n");
  scanf("%d", &s);
  switch (s) {
    case 1:
      printf("enter the key value\n");
      scanf("%d", &k);
      printf("Enter the length of text:\n");
      scanf("%d", &n);
      printf("Enter the data to be encrypted:\n");
      for (i = 0; i <= n; i++) {
	scanf(" %c", &c[i]);
      }
      for (i = 0; i <= n; i++) {
	c[i] = c[i] + k;
	if (c[i] > 'z')
	  c[i] = c[i] - 26;
	if (c[i] < 'a')
	  c[i] = c[i] + 26;
      }
     // printf("Encrypted text is: %s\n", ct);
      printf("encrypted data: ");
      for (i = 1; i< n; i++)
	printf("%c", c[i]);
      printf("\n");
      break;

    case 2:
      printf("enter the key value\n");
      scanf("%d", &k);
      printf("Enter the length of text:\n");
      scanf("%d", &n);
      printf("Enter the data to be decryption:\n");
      for (i = 0; i<n ;i++) {
	scanf(" %c", &c[i]);
      }
      for (i = 0; i < n; i++) {
	c[i] = c[i] - k;
	if (c[i] < 'a') {
	  c[i] = c[i] + 26;
	}
      }
      printf("decrypted data: ");
      for (i = 0; i <= n; i++)
	printf("%c", c[i]);
      printf("\n");
      break;

    case 3:
      break;
    default:
      printf("Wrong choice\n");
  }
  getch();
  return 0;
}
//sample output
/*
In program 1. Encryption and decryption
1
enter the key value
3
Enter the length of text:
5
Enter the data to be encrypted:
hello
Encrypted text is: khoor
encrypted data: khoor
*/
/*
In program 1. Encryption and decryption
2
enter the key value
3
Enter the length of text:
5
Enter the data to be decryption:
khoor
decrypted data: hello

*/