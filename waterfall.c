// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2
#include <stdio.h>
#include <stdint.h>

#define bool int8_t
#define true 1
#define false 0

#define SIZE_a ((int) (sizeof(a) / sizeof(a[0])))

void interest_c(void) {
    printf("Enter interest rate: ");
    int rate; scanf("%d", &rate);
    printf("Enter number of years: ");
    int yrs; scanf("%d", &yrs);

    // table headers
    float a[5];
    printf("\nYears"); 
    for (int i = 0; i < SIZE_a; i++) {
        printf("%6d%%", rate + i);
        a[i] = 100.00f; // init all values to 100.00f
    }
    printf("\n");

    // Table contents
    for (int i = 1; i <= yrs; i++) {
        printf("%3d   ", i); // Year number

        // Int rates
        for (int j = 0; j < SIZE_a; j++) {
            int rt = rate + j;
            // Display and update array
            printf("%7.2f ", a[j] *= (rt / 100.0f + 1.0f));
        }

        printf("\n");
    }
}

int main(void) {
    interest_c();
    return 0;
}

