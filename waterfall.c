// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2
#include <stdio.h>
#include <stdint.h>
#define bool int8_t
#define true 1
#define false 0

#define N 5
void revnum(void) {
    // Reverses a series of numbers
    printf("Enter %d numbers: ", N);
    int ns[N];
    for (int i = 0; i < N; i++) scanf("%d", &ns[i]);

    printf("In reverse order: ");
    for (int i = N-1; i >= 0; i--) printf("%d ", ns[i]);
}

void repdig(void) {
    // Checks numbers for repeated digits
    printf("Enter a number: ");
    int n; scanf("%d", &n);

    bool dig_seen[10] = {false};
    while (n > 0) {
        if (dig_seen[n%10]) break;

        dig_seen[n%10] = true;
        n /= 10;
    }

    printf("%s\n", n > 0 ? "Repeated digit" : "No repeated digit");
}

int main(void) {
    repdig();
    return 0;
}

