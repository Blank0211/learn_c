#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>

int main(void) {
    // Variables
    uint8_t f_vals[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 
                          5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 
                          1, 4, 4, 8, 4, 10};
    uint16_t sum = 0;
    unsigned char c;

    // Input
    printf("Enter a word: ");
    while ((c = getchar()) != '\n') {
        c = toupper(c); // Allow mixture of lower & upper case letters
        sum += f_vals[c - 'A'];
    }
    // Output
    printf("Scrabble value: %d\n", sum);

    return 0;
}

