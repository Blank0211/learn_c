// % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2

#include <stdio.h>

int gcd(int n, int m) {
    if (n <= 0 || m <= 0) {
        printf("Invalid Value: One of two integers is zero or negative!\n");
        return 0;
    }

    while (n != m) {
        if (n > m) n -= m;
        else       m -= n;
    }
    return n;
}

void frac(void) {
    printf("Enter two fractions separated by an operator: ");
    int n1, n2, d1, d2; char operator;
    scanf("%d /%d %c %d /%d", &n1, &d1, &operator, &n2, &d2);

    // Calculate
    int res_n, res_d;
    switch (operator) {
        case '+':
            res_n = n1 * d2 + n2 * d1;
            res_d = d1 * d2;
            break;
        case '-':
            res_n = n1 * d2 - n2 * d1;
            res_d = d1 * d2;
            break;
        case '*':
            res_n = n1 * n2;
            res_d = d1 * d2;
            break;
        case '/':
            res_n = n1 * d2;
            res_d = n2 * d1;
            break;
        default:
            printf("INVALID OPERATOR!\n");
            return; // Exit function
    }

    // Simplify fraction
    int gc = gcd(res_n, res_d);
    res_n /= gc; res_d /= gc;

    if (res_d == 1)                                 // e.g. 3/1 which is just 3
        printf("Result: %d\n", res_n);
    else if (res_n > res_d)                              // Improper Fractions
        printf("Result: %d %d/%d\n", res_n/res_d, res_n%res_d, res_d);
    else                                                 // Proper Fractions
        printf("Result: %d/%d\n", res_n, res_d);
}

int main(void) {
    frac();
    return 0;
}

