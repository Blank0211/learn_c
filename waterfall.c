// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdint.h>

#define bool _Bool
#define true 1
#define false 0

void avg_temps(void) {
    const uint8_t days = 30, hours = 24;
    double temp_readings[days][hours];
    for (int d = 0; d < days; d++) {// Set all values to 30.0
        for (int h = 0; h < hours; h++)
            temp_readings[d][h] = 30.0;
    }

    double tmp_avg = 0.0;
    for (int d = 0; d < days; d++) {
        for (int h = 0; h < hours; h++)
            tmp_avg += temp_readings[d][h];
    }

    tmp_avg /= (days * hours);
    printf("Average temp for month: %.2f\n", tmp_avg);
}

int main(void) {
    avg_temps();
    return 0;
}

