#include <stdio.h>
#define SIZE_a ((int) (sizeof(a) / sizeof(a[0])))

void interest_c(void) {
    printf("Enter interest rate: ");
    int rate; scanf("%d", &rate);
    printf("Enter number of years: ");
    int yrs; scanf("%d", &yrs);

    // Table headers
    float a[5];
    for (int i = 0; i < SIZE_a; i++) {
        printf("%7d%%", rate + i);
        a[i] = 100.00f; // init all values to 100.00f
    }
    printf("\n");

    // Table contents
    for (int i = 1; i <= yrs; i++) {
        printf("   ");
        // Int rates
        for (int j = 0; j < SIZE_a; j++) {
            int rt = rate + j;

            // Compound intrest monthly.
            for (int m = 0; m < 12; m++) 
                a[j] *= ((double) rt / 12.0 / 100.0f + 1.0f);
            printf("%7.2f ", a[j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    interest_c();
    return 0;
}

