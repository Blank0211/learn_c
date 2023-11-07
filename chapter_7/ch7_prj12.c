// [[ Chapter 7, Project 12 ]]
//
// Write a program that evaluates an expression:
//
// ==== PROGRAM EXAMPLE ====
// Enter an expression: 1+2.5*3
// Value of expression: 10.5
// ==== EXAMPLE END ====
//
// The operands in the expression are floating-point numbers;
// the operators are +, -, *, and /. The expression is evaluated from
// left to right (no operator takes precedence over any other operator).


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

