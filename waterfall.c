// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "utils.h"

#define bool _Bool
#define true 1
#define false 0

void fl_name(void) {
    // Data
    char initial, c;
    char l_name[21] = {0}; // Initialize all chars to NUL

    // Input
    printf("Enter a first and last name: ");
    while ((initial = getchar()) == ' ') ; // Get first char of FN
    while ((c = getchar()) != ' ') ; // Eat rest of chars in FN

    int i = 0;
    while (i < 20) {
        c = getchar();
        if (c == ' ') continue; // Skip spaces before, in-between & after LN
        if (c == '\n') break;

        l_name[i] = c;
        i++;
    }

    // Output
    printf("%s, %c.\n", l_name, initial);
}

int main(void) {
    fl_name();
    return 0;
}

