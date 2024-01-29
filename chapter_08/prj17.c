#include <stdio.h>
#include <inttypes.h>

void mv_fw(uint8_t *x, uint8_t *y, uint8_t sq_size) {
    // move forward: one up, one right
    *x = *x <= 0 ? sq_size-1 : *x - 1;
    *y = (*y + 1) % sq_size;
}
void mv_bw(uint8_t *x, uint8_t *y, uint8_t sq_size) {
    // move backward: one right, two down.
    *y = *y <= 0 ? sq_size-1 : *y - 1;
    *x = (*x + 1) % sq_size;
    *x = (*x + 1) % sq_size;
}

int main(void) {
    printf("This program creates a magic square of specified size.\n"
           "The size must be an add number between 1 and 99.\n");

    // === [[ INPUT ]] ===
    printf("Enter the size of magic square: ");
    char buf[4] = {0};
    if (fgets(buf, 4, stdin) == NULL) {
        printf("\nERROR: fgets returned NULL\n"); return 0;
    }

    // parse & verify input (else terminate)
    uint8_t sq_size = 0;
    if (sscanf(buf, "%" SCNu8, &sq_size) < 1) {
        printf("\nERROR: scanf could read input\n"); return 0;
    }
    if (1 > sq_size || sq_size > 99) {
        printf("\nINVALID VAL: Outside of 1-99\n"); return 0;
    }
    if (sq_size % 2 == 0) {
        printf("\nINVALID VAL: Even number\n"); return 0;
    }

    // === [[ PROCESS ]] ===
    uint16_t sq[sq_size][sq_size];
    for (uint8_t r = 0; r < sq_size; r++)
        for (uint8_t c = 0; c < sq_size; c++)
            sq[r][c] = 0; // Init all elements to 0

    uint8_t x = 0;
    uint8_t y = sq_size / 2;
    sq[x][y] = 1;
    for (int i = 1; i < sq_size*sq_size; i++) {
        mv_fw(&x, &y, sq_size);
        if (sq[x][y] != 0)
            mv_bw(&x, &y, sq_size);

        // printf("x = %d | y = %d | i = %d\n", x, y, i);
        sq[x][y] = i+1;
    }

    // === [[ OUTPUT ]] ===
    for (uint8_t c = 0; c < sq_size; c++) {
        printf("   ");
        for (uint8_t r = 0; r < sq_size; r++)
            printf("%3d   ", sq[c][r]);
        printf("\n");
    }
    return 0;
}

