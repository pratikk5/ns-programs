#include <stdio.h>
#include <string.h>

void charc(void);

void main() {
    int choice;

    while (1) {
        printf("\n\n\n 1. Character Stuffing");
        printf("\n 2. Exit");
        printf("\n\n Enter choice: ");
        scanf("%d", &choice);
        printf("You entered: %d\n", choice);

        if (choice > 2)
            printf("\n\nInvalid option. Please re-enter.");

        switch (choice) {
            case 1:
                charc();
                break;
            case 2:
                return;
        }
    }
}

void charc(void) {
    char c[50], d[100], t[50];
    int i, m, j = 0, k = 6;

    printf("\n Enter the number of characters: ");
    scanf("%d", &m);
    getchar(); // To consume newline after number input

    printf("\n Enter the Characters \n");
    for (i = 0; i < m; i++)
        scanf("%c", &c[i]);

    printf("\n Original Data \n");
    for (i = 0; i < m; i++)
        printf("%c", c[i]);

    d[0] = 'd';
    d[1] = 'l';
    d[2] = 'e';
    d[3] = 's';
    d[4] = 't';
    d[5] = 'x';

    for (i = 0; i < m; i++) {
        if (c[i] == 'd' && c[i + 1] == 'l' && c[i + 2] == 'l') {
            d[k++] = 'd';
            d[k++] = 'l';
            d[k++] = 'e';
        }
        d[k++] = c[i];
    }

    d[k++] = 'd';
    d[k++] = 'l';
    d[k++] = 'e';
    d[k++] = 'e';
    d[k++] = 't';
    d[k++] = 'x';

    printf("\n\n Transmitted Data \n");
    for (i = 0; i < k; i++) {
        printf("%c", d[i]);
    }

    j = 0;
    for (i = 6; i < k - 6; i++) {
        if (d[i] == 'd' && d[i + 1] == 'l' && d[i + 2] == 'e') {
            i += 3;
        }
        t[j++] = d[i];
    }

    printf("\n\n Received Data \n");
    for (i = 0; i < j; i++) {
        printf("%c", t[i]);
    }
}
/*  
1.Character stuffing
2.exit

 enter choice 1

 Enter the number of characters 6

 Enter the Character 
pratik

 Original Data
pratik
 
 transmitted data
dlestxpratikdleetx

 Received Data
pratik
*/