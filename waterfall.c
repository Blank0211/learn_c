// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdint.h>

#define bool _Bool
#define true 1
#define false 0

#define ROW 8
#define COL 8
void chess(void) {
    char board[ROW][COL] = { {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, 
                             {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                             {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                             {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                             {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                             {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                             {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                             {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}, };
    // Display board
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++)
            printf(" %c", board[r][c]);
        printf("\n");
    }
}

int main(void) {
    chess();
    return 0;
}

