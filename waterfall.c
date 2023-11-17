// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define bool int8_t
#define true 1
#define false 0

void deal_c(void) {
    printf("Enter number of cards in hand: ");
    int n_crd; scanf("%d", &n_crd);

    bool in_hand[4][13]  =  {false}; // Will represent cards already in-hand
    const char suits[4]  =  {'s', 'c', 'd', 'h'};
    const char ranks[13] =  {'2', '3', '4', '5', '6', '7', '8', '9', '0',
                             'j', 'q', 'k', 'a'}; // '0' is ten

    srand(time(NULL)); // Provide seed for rand()
    int st, rnk;
    printf("Your hand:");
    while (n_crd > 0) {
        // Pick a random card
        st = rand() % 4;
        rnk = rand() % 13;
        if (in_hand[st][rnk]) continue;

        printf(" %c%c",ranks[rnk], suits[st]); // Display card
        in_hand[st][rnk] = true;               // and mark it as in-hand

        n_crd--;
    }
    printf("\n");
}

int main(void) {
    deal_c();
    return 0;
}

