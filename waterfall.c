// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "utils.h"

#define bool _Bool
#define true 1
#define false 0

#define DEPS 8
#define ARRS 8
void dep(void) {
    uint16_t d_t[DEPS][2] = {
       {8, 0},      // Rows (2) represent hours and mins
       {9, 43},     // Columns (8) represent departure times
       {11, 19},
       {12, 47},
       {14, 0},
       {15, 45},
       {19, 0},
       {21, 45},
    };

    uint16_t a_t[ARRS][2] = {
        {10, 16},   // Rows (2) represent hours and mins
        {11, 52},   // Columns (8) represent arrival times
        {13, 31},
        {15, 0},
        {16, 6},
        {17, 55},
        {21, 20},
        {23, 58},
    };
    
    // Get input (user-time)
    printf("Enter a 24-hour time: ");
    char buf[80]; fgets(buf, sizeof(buf), stdin);
    uint8_t h, m; sscanf(buf, "%" SCNu8 " :%" SCNu8, &h, &m);
    uint16_t usr_time = h * 60 + m;

    // Normalized dep times: abs(time-in-mins MINUS usertime)
    uint16_t nd_t[DEPS];
    for (int i = 0; i < DEPS; i++)
        nd_t[i] = abs((d_t[i][0] * 60 + d_t[i][1]) - usr_time);

    // Compare normalized dep times (to see which is closer to user-time)
    int d;
    for (d = 0; d < DEPS - 1; d++) {
        if (nd_t[d] < nd_t[d+1])
           break; // Break out of loop when closest dep time found
    }


    int d_hour = to_12h(d_t[d][0]);
    int d_mins = d_t[d][1];
    char *d_ampm = ampm(d_t[d][0]);
    
    int a_hour = to_12h(a_t[d][0]);
    int a_mins = a_t[d][1];
    char *a_ampm = ampm(a_t[d][0]);
    
    // Display dep & arr time
    printf("Closest departure time is %.2d:%.2d %s, ", d_hour, d_mins, d_ampm);
    printf("arriving at %.2d:%.2d %s\n", a_hour, a_mins, a_ampm);
}

int main(void) {
    dep();
    return 0;
}

