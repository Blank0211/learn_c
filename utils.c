#include <stdio.h>
#include <stdlib.h> // Defines: exit, strtol
#include <inttypes.h>
#include <errno.h> // Defines: errno, ERANGE
#include "utils.h"

#define BUF_SIZE 32 // Used in get_d32;

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

// Returns: 0 on success. 1 if strtol fails. 2 if input out of range.
int8_t get_d32(int32_t *n) {
    long tmp = 0;
    *n = 0;

    // === [[ INPUT ]] ===
    printf("Enter a number: ");
    char buf[BUF_SIZE] = {0};
    uint8_t i = 0; // buf index
    char c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < BUF_SIZE) buf[i++] = c;
    }

    // === [[ PROCESS INPUT ]] ===
    // errno can be set to any non-zero value by a library function call
    // regardless of whether there was an error, so it needs to be cleared
    // in order to check the error set by strtol
    errno = 0;
    char *end;
    tmp = strtol(buf, &end, 10);
    if (end == buf) {
        printf("\n --> strtol could not convert input\n");
        return 1;
    }
    if (errno == ERANGE) {
        printf("\n --> Range error occured.\n");
        return 2;
    }
    
    // === [[ SET n ]] ===
    // Execution should only reach here if previous steps are successful.
    // Set value of n.
    if      (tmp > INT32_MAX) *n = INT32_MAX;
    else if (tmp < INT32_MIN) *n = INT32_MIN;
    else                      *n = (int32_t) tmp;
    return 0;
}


