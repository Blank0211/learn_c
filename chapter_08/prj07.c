#include <stdio.h>
#include <inttypes.h>

#define ROW 5
#define COL 5

void r5c5_sum(void) {
    uint16_t n[ROW][COL];
    char buf[128];
    // Get input
    for (int r = 0; r < ROW; r++) {
        printf("Enter row %d: ", r);
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%hu %hu %hu %hu %hu", 
                &n[r][0], &n[r][1], &n[r][2], &n[r][3], &n[r][4]);
    }

    // Dispaly sums
    uint32_t total = 0;
    printf("\nRow totals: ");
    for (int r = 0; r < ROW; r++) {
        total = n[r][0] + n[r][1] + n[r][2] + n[r][3] + n[r][4];
        printf(" %" PRIu32, total);
    }
    printf("\n");

    printf("Column totals: ");
    for (int c = 0; c < 5; c++) {
        total = n[0][c] + n[1][c] + n[2][c] + n[3][c] + n[4][c];
        printf(" %" PRIu32, total);
    }
    printf("\n");
}

int main(void) {
    r5c5_sum();
    return 0;
}

