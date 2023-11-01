// [[ Chapter 7, Project 12 ]]
#include <stdio.h>

void evaler(void) {
    float running_total = 0.0f, next_num = 0.0f;
    char c;

    printf("Enter a expression: ");
    scanf("%f", &running_total);
    
    while ((c = getchar()) != '\n') {
        switch (c) {
            case '+':
                scanf("%f", &next_num);
                running_total += next_num;
                break;
            case '-':
                scanf("%f", &next_num);
                running_total -= next_num;
                break;
            case '*':
                scanf("%f", &next_num);
                running_total *= next_num;
                break;
            case '/':
                scanf("%f", &next_num);
                running_total /= next_num;
                break;
        }
    }
    printf("Value of expression: %.2f\n", running_total);
}

int main(void) {
    evaler();
    return 0;
}

