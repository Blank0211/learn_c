#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

#define bool _Bool
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

void walk(void) {
    // Create a 10x10 map
    uint8_t row = 10, col = 10;
    char map[row][col];
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            map[r][c] = '.'; // Set every element to '.'
 
    // Necessary variables for next moves
    srand(time(NULL));
    bool blocked_l, blocked_r, blocked_u, blocked_d; // blocked directions
    int8_t nxt_move;
    int8_t pos_x = 0, pos_y = 0;
    char ltr = 'A';

    // Start Walk
    map[pos_x][pos_y] = ltr++; // first move
    while (ltr <= 'Z') {
        nxt_move = rand() % 4;

        // Check if surrounding directions are blocked:
        // a direction is blocked if (a) it is outsite the map
        // or (b) it already has a letter assigned
        blocked_r = !(pos_y < 9) || map[pos_x][pos_y+1] != '.';
        blocked_l = !(pos_y > 0) || map[pos_x][pos_y-1] != '.';
        blocked_u = !(pos_x > 0) || map[pos_x-1][pos_y] != '.';
        blocked_d = !(pos_x < 9) || map[pos_x+1][pos_y] != '.';

        // Terminate program if all direction blocked
        if (blocked_r && blocked_l && blocked_u && blocked_d) break;
        // redo if next move is toward blocked direction
        if (nxt_move == UP && blocked_u) continue; 
        if (nxt_move == DOWN && blocked_d) continue; 
        if (nxt_move == RIGHT && blocked_r) continue; 
        if (nxt_move == LEFT && blocked_l) continue; 

        // Set next position
        switch (nxt_move) {
            case UP:    pos_x--; break;
            case DOWN:  pos_x++; break;
            case LEFT:  pos_y--; break;
            case RIGHT: pos_y++; break;
        }

        // Move to next position (then update ltr)
        map[pos_x][pos_y] = ltr++;
    }

    // Display map after walk.
    printf("\n   0 1 2 3 4 5 6 7 8 9\n");
    for (int r = 0; r < row; r++) {
        printf("%d ", r);
        for (int c = 0; c < col; c++)
            printf(" %c", map[r][c]);
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    walk();
    return 0;
}

