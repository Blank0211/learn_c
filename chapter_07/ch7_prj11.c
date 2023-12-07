// [[ Chapter 7, Project 11: ]]
// Write a program that takes a first name and last name entered by the user
// and displays the last name, a comma, and the first initial,
// followed by a period.
//
// ==== PROGRAM EXAMPLE ====
// Enter a first and last name: Lloyd Fosdick
// Fosdick, L.
// ==== EXAMPLE END ====
//
// The user may input extra spaces before the first name,
// between the first and last names, and after the last name.

#include <stdio.h>
#include <ctype.h>

void fl_name(void) {
    char c, initial;

    printf("Enter a first and last name: ");
    while ((initial = getchar()) == ' ') ; // Allow spaces before FN & get initial
    while (getchar() != ' ') ; // Eat & discard rest of the chars in FN

    while ((c = getchar()) != '\n') {
        if (c == ' ') continue; // Allow spaces before LN
        printf("%c", c); // Start printing LN
    } printf(", ");

    printf("%c.\n", initial); // Print the first initial
}

int main(void) {
    fl_name();
    return 0;
}

