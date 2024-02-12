// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "utils.h"

#define bool _Bool
#define true 1
#define false 0

bool is_prime(int32_t n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;

    return true;
}

int main(void) {
    // Tests whether a number is prime
    // [[ INPUT ]]
    printf("Enter a number: ");
    char buf[6];
    if (fgets(buf, 6, stdin) == NULL) err_exit(1);

    int32_t n;
    if (sscanf(buf, "%d", &n) < 1) err_exit(2);
    
    // [[ OUTPUT ]]
    if (is_prime(n)) printf("Prime\n");
    else printf("Not prime\n");

    return 0;
}

