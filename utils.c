#include "utils.h"

int abs(int n) { return n < 0 ? -n : n; }

char *ampm(int hour_24) {
    if (hour_24 < 12) return "A.M.";
    return "P.M.";
}

int to_12h(int hour_24) {
    if (hour_24 == 0) return 12;
    if (hour_24 <= 12) return hour_24;
    return hour_24 % 12;
}

