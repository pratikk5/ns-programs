#include <string.h>
#include <stdio.h>

int main() {
    char a[20], fs[50] = " ", t[6], r[5];
    int i, j, p = 0, q = 0;

    printf("Enter the bit string: ");
    scanf("%s", a); 

    strcat(fs, "01111110_"); 

    if (strlen(a) < 5) {
        strcat(fs, a);
    } else {
        for (i = 0; i < strlen(a) - 4; i++) {
            for (j = i; j < i + 5; j++) {
                t[p++] = a[j];
            }
            t[p] = '\0';
            if (strcmp(t, "11111") == 0) {
                strcat(fs, "111110");
                i = i + 4; // Skip the matched sequence
            } else {
                r[0] = a[i];
                r[1] = '\0';
                strcat(fs, r);
            }
            p = 0;
        }
        for (q = i; q < strlen(a); q++) {
            t[p++] = a[q];
        }
        t[p] = '\0';
        strcat(fs, t);
    }

    strcat(fs, "_01111110");

    printf("after stuffing : %s\n", fs); // Added newline character

    return 0;
}
/* 
enter the bit string: 101011111000
after stuffing : 01111110_1010111110000_01111110
*/