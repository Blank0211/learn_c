// [[ Chapter 7, Project 15 ]]
// Write a program that computes the factorial of a positive integer.

#include <stdio.h>

// Uses two variables: n, sum
void fac(void) {
    printf("Enter a positive integer: ");
    int n; scanf("%d", &n);

    int sum = n;
    for (int i = n-1; i > 1; i--) {
        sum *= i;
    }
    printf("Factorial of %d: %d\n", n, sum);
}

// Uses one variable: n
void fac2(void) {
    printf("Enter a positive integer: ");
    int n; scanf("%d", &n);

    printf("Factorial of %d: ", n);
    for (int i = n-1; i > 1; i--) {
        n *= i;
    }
    printf("%d\n", n);
}

int main(void) {
    fac2();
    return 0;
}

