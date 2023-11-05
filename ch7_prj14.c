// [[ Chapter 7, Project 14 ]]

#include <stdio.h>
#include <math.h>

void sq_rt(void) {
    printf("Enter a positive number: ");
    int x; scanf("%d", &x);

    double y = 1.0;
    double diff = fabs(((y + x/y) / 2) - y); // Difference between old y and y
    
    while (diff > .00001 * y) {
        y = (y + x/y) / 2;
        diff = fabs(((y + x/y) / 2) - y);
        
        // Show info in each iteration
        printf("y: %lf  |  diff: %lf  |  Tol: %lf\n", y, diff, .00001*y);
    }
    printf("Square root: %lf\n", y);
}

int main(void) {
    sq_rt();
    return 0;
}

