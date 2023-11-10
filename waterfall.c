// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2
#include <stdio.h>
#define N 5

void revnum(void) {
    // Reverses a series of numbers
    printf("Enter %d numbers: ", N);
    int ns[N];
    for (int i = 0; i < N; i++) scanf("%d", &ns[i]);

    printf("In reverse order: ");
    for (int i = N-1; i >= 0; i--) printf("%d ", ns[i]);
}

int main(void) {
    revnum();
    return 0;
}

