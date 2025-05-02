#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int fast_exponentiation(int base, unsigned int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void generate_keys(int P, int Q, int *n, int *e, int *d) {
    *n = P * Q;
    int phi = (P - 1) * (Q - 1);
    *e = 2;

    while (*e < phi) {
        if (gcd(*e, phi) == 1)
            break;
        (*e)++;
    }

    int k = 1;
    while (1) {
        k = k + phi;
        if (k % *e == 0) {
            *d = k / *e;
            break;
        }
    }
}

int encrypt(int message, int e, int n) {
    return fast_exponentiation(message, e, n);
}

int decrypt(int message, int d, int n) {
    return fast_exponentiation(message, d, n);
}

int main() {
    int P, Q, n, e, d;
    printf("Enter the values of P and Q (prime numbers): ");
    scanf("%d %d", &P, &Q);

    generate_keys(P, Q, &n, &e, &d);

    int message;
    printf("Enter the message to encrypt: ");
    scanf("%d", &message);

    int encrypted_message = encrypt(message, e, n);
    printf("Encrypted message: %d\n", encrypted_message);

    int decrypted_message = decrypt(encrypted_message, d, n);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int gcd(int a, int b) {
    if (b == 0)
	return a;
    return gcd(b, a % b);
}

int fast_exponentiation(int base, unsigned int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
	if (exp % 2 == 1)
	    result = (result * base) % mod;
	exp = exp >> 1;
	base = (base * base) % mod;
    }
    return result;
}

void generate_keys(int P, int Q, int *n, int *e, int *d) {
    int phi,k;
    *n = P * Q;

    phi = (P - 1) * (Q - 1);
    *e = 2;

    while (*e < phi) {
	if (gcd(*e, phi) == 1)
	    break;
	(*e)++;
    }

    k = 1;
    while (1) {
	k = k + phi;
	if (k % *e == 0) {
	    *d = k / *e;
	    break;
	}
    }
}

int encrypt(int message, int e, int n) {
    return fast_exponentiation(message, e, n);
}

int decrypt(int message, int d, int n) {
    return fast_exponentiation(message, d, n);
}

int main() {
    int P, Q, n, e, d,message,encrypted_message,decrypted_message;
    printf("Enter the values of P and Q (prime numbers): ");
    scanf("%d %d", &P, &Q);

    generate_keys(P, Q, &n, &e, &d);


    printf("Enter the message to encrypt: ");
    scanf("%d", &message);

    encrypted_message = encrypt(message, e, n);
    printf("Encrypted message: %d\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, d, n);
    printf("Decrypted message: %d\n", decrypted_message);
    getch();
    return 0;
}
//sample output
/*
Enter the values of P and Q (prime numbers): 7 11
Enter the message to encrypt: 9
Encrypted message: 3
Decrypted message: 9
*/