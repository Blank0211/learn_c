// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdint.h>

#define bool _Bool
#define true 1
#define false 0

void fib(void) {
    uint32_t fibs[40] = {0, 1};
    for (int i = 2; i < 40; i++)
        fibs[i] = fibs[i-1] + fibs[i-2];

    for (int i = 0; i < 40; i++) printf("%d, ", fibs[i]);
}

int main(void) {
    fib();
    return 0;
}

