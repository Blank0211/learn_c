// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdint.h>

#define bool _Bool
#define true 1
#define false 0

#define DIGS 10
void repdig(void) {
    // Checks a number for repeated digits and prints a table
    // showing how many time each digit appears in number.
    printf("Enter a number: ");
    int n; scanf("%d", &n);

    // Check the number
    int8_t dig_seen[DIGS] = {0};
    while (n > 0) {
        dig_seen[n%10]++;
        n /= 10;
    }

    // Print table
    printf("Digit:        0  1  2  3  4  5  6  7  8  9\n");
    printf("Occurrences:  ");
    for (int i = 0; i < DIGS; i++)
        printf("%d  ", dig_seen[i]);
}

int main(void) {
    repdig();
    return 0;
}

