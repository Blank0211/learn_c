// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdint.h>

#define bool _Bool
#define true 1
#define false 0

#define ROW 8
#define COL 8
void chkr(void) {
    char checker_board[ROW][COL] = {0};

    // Set values
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++)
            checker_board[r][c] = (r + c) % 2 == 0 ? 'B' : 'R';
    }

    // Display checker board
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++)
            printf(" %c", checker_board[r][c]);
        printf("\n");
    }
}

int main(void) {
    chkr();
    return 0;
}

