// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdint.h>

#define bool _Bool
#define true 1
#define false 0

#define DIGS 10
void repdig(void) {
    // Checks numbers for repeated digits
    // and shows which digits (if any) were repeated
    printf("Enter a number: ");
    int n; scanf("%d", &n);

    bool dig_seen[DIGS] = {false};
    bool dig_repeat[DIGS]= {false}
    while (n > 0) {
        if (dig_seen[n%10]) dig_repeat[n%10] = true;

        dig_seen[n%10] = true;
        n /= 10
    }

    // Display repeated digits (if any)
    printf("Repeated digit(s): ");
    for (int i = 0; i < DIGS; i++)
        if (dig_repeat[i]) printf("%d ", i);
    printf("\n");
}

int main(void) {
    what();
    return 0;
}

