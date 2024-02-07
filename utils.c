#include <stdio.h>
#include <stdlib.h> // Defines: exit
#include <inttypes.h>
#include "utils.h"

int abs(int n) { return n < 0 ? -n : n; }

char *ampm(int hour_24) {
    if (hour_24 < 12) return "A.M.";
    return "P.M.";
}

int to_h12(int hour_24) {
    if (hour_24 == 0) return 12;
    if (hour_24 <= 12) return hour_24;
    return hour_24 % 12;
}

void err_exit(uint8_t err_num) {
    printf("\nERROR_%" PRIu8 "\n", err_num);
    exit(0);
}

