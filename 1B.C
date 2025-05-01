#include <stdio.h>
#include <string.h>

void charc(char d[], int sn);

int main() {
    int choice;

    while (1) {
        printf("\n\n\n1. Character Stuffing");
        printf("\n2. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);
        printf("You entered: %d\n", choice);

        if (choice > 2) {
            printf("\n\nInvalid option. Please re-enter.");
        } else {
            switch (choice) {
                case 1: {
                    char data[50]; // Assuming a maximum data length of 50
                    int n, i;

                    printf("\nEnter the number of characters: ");
                    scanf("%d", &n);
                    printf("Enter the characters: ");
                    for (i = 0; i < n; i++) {
                        scanf(" %c", &data[i]); // Note the space before %c
                    }
                    charc(data, n);
                    break;
                }
                case 2:
                    return 0;
            }
        }
    }
    return 0;
}

void charc(char d[], int sn) {
    char c[150]; // Assuming a maximum stuffed data length
    int i, j = 0;
    char delimiter = 4; // ASCII for EOT
    char escape = 2;    // ASCII for STX
    char r[150];       // Array to store the unstuffed data
    int k = 0;

    printf("\nOriginal data: ");
    for (i = 0; i < sn; i++) {
        printf("%c", d[i]);
    }
    printf("\n");

    // Character Stuffing
    for (i = 0; i < sn; i++) {
        if (d[i] == delimiter) {
            c[j++] = escape;
            c[j++] = delimiter;
            c[j++] = escape;
        } else if (d[i] == escape) {
	    c[j++] = escape;
            c[j++] = escape;
        } else {
            c[j++] = d[i];
        }
    }
    c[j] = '\0';

    printf("\nTransmitted data (stuffed): ");
    printf("%s\n", c);

    // Character Unstuffing
    for (i = 0; c[i] != '\0'; i++) {
        if (c[i] == escape) {
            i++;
            if (c[i] == delimiter && c[i + 1] == escape) {
                r[k++] = delimiter;
                i++;
            } else if (c[i] == escape) {
                r[k++] = escape;
            } else {
                r[k++] = c[i];
            }
        } else {
            r[k++] = c[i];
        }
    }
    r[k] = '\0';

    printf("\nReceived data (unstuffed): ");
    printf("%s\n", r);
}