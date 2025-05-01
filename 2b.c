#include <stdio.h>
#include <string.h>
#include <conio.h> // Include for getch()
#define N strlen(g)
char t[128], cs[128], g[18] = "10001000000100001";
int a, e, c;
void XOR() {
  for (c = 1; c < N; c++) cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}
void crc() {
  for (e = 0; e < N; e++) cs[e] = t[e];
  do {
    if (cs[0] == '1') XOR();
    for (c = 0; c < N - 1; c++) cs[c] = cs[c + 1];
    cs[c] = t[e++];
  } while (e < a + N - 1);
}
int main() {
  printf("Enter poly:");
  scanf("%s", t);
  printf("\nGenerating polynomial is:%s", g);
  a = strlen(t);
  for (e = a; e < a + N - 1; e++) t[e] = '0';
  printf("\nModified t[u]: %s", t);
  crc();
  printf("\nChecksum is:%s", cs);
  for (e = a; e < a + N - 1; e++) t[e] = cs[e - a];
  printf("\nFinal code word is: %s", t);
  printf("\nTest error detection 0(yes) 1(No)? :");
  scanf("%d", &e);
  if (e == 0) {
    printf("Enter position where error is to be inserted :");
    scanf("%d", &e);
    t[e] = (t[e] == '0' ? '1' : '0');
    printf("Errornous data :%s\n", t);
  }
  crc();
  for (e = 0; (e < N - 1) && (cs[e] == '0'); e++);
  if (e < N - 1)
    printf("error detected");
  else
    printf("no error detected");

  getch(); // Add this line to pause the output

  return 0;
}
//sample output
/*
Enter poly:10101

Generating polynomial is:10001000000100001
Modified t[u]: 101010000000000000000
Checksum is:001000001010010100
Final code word is: 1010100100000101001010
Test error detection 0(yes) 1(No)? :0
Enter position where error is to be inserted :4
Errornous data :1010000100000101001010
error detected_
*/
