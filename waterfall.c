// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define bool _Bool
#define true 1
#define false 0

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
bool chk_lu(uint8_t n) { return !(n > 0); }
bool chk_rd(uint8_t n) { return !(n < 9); }

void walk(void) {
    // Create a 10x10 map
    uint8_t row = 10, col = 10;
    char map[row][col];
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            map[r][c] = '.'; // Set every element to '.'
 
    char alph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                     'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                     'X', 'Y', 'Z'};

    srand(time(NULL));
    bool blocked_l, blocked_r, blocked_u, blocked_d;
    int8_t pos_x = 0, pos_y = 0, ltr = 0, nxt_move;
    map[pos_x][pos_y] = alph[ltr++]; // first move

    while (ltr < 26) {
        nxt_move = rand() % 4;

        // Check if at boundary or next point already used
        blocked_r = chk_rd(pos_y) || map[pos_x][pos_y+1] != '.';
        blocked_l = chk_lu(pos_y) || map[pos_x][pos_y-1] != '.';
        blocked_u = chk_lu(pos_x) || map[pos_x-1][pos_y] != '.';
        blocked_d = chk_rd(pos_x) || map[pos_x+1][pos_y] != '.';

        // Terminate program if surrounded
        if (blocked_r && blocked_l && blocked_u && blocked_d) break;
        // Check if next move is valid
        if (nxt_move == UP && blocked_u) continue; 
        if (nxt_move == DOWN && blocked_d) continue; 
        if (nxt_move == RIGHT && blocked_r) continue; 
        if (nxt_move == LEFT && blocked_l) continue; 

        // Set next position
        if (nxt_move == UP) pos_x--;
        if (nxt_move == DOWN) pos_x++;
        if (nxt_move == LEFT) pos_y--;
        if (nxt_move == RIGHT) pos_y++;

        // Move to next position
        map[pos_x][pos_y] = alph[ltr++];
    }

    // Display map
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++)
            printf(" %c", map[r][c]);
        printf("\n");
    }
}

int main(void) {
    walk();
    return 0;
}

