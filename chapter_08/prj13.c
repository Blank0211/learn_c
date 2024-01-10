// Reverse words in a sentence

#include <stdio.h>

#define SIZE 81
int main(void) {
    // [[ Input ]]
    char term_char; // Terminating character
    char sent[SIZE] = {0}; // Sentence entered by user.
    char c;

    printf("Enter a sentence: ");
    int s_i; // sent index
    for (s_i = 0; s_i < SIZE-1; s_i++) { // "SIZE-1": exclude last elemtent
        c = getchar();
        if (c == '.' || c == '?' || c == '!' || c == '\n') {
            term_char = c; 
            break; // Terminate loop
        }

        sent[s_i] = c;
    }

    // [[ Process input ]] 
    char rev_sent[SIZE] = {0}; // Reverse sent
    int rs_i = 0; // Index for rev_sent
    int lw_strt = s_i; // Keep track of last word's start position

    for (int i = SIZE-2; i >= 0; i--) { // "SIZE-2": start from 2nd-last element
        // A word starts if there's space before it
        // or if it's at the beginning of a sentence
        if (sent[i] == ' ') {
            for (int j = i+1; j < lw_strt; j++) // "i+1": skip space
                rev_sent[rs_i++] = sent[j];
            rev_sent[rs_i++] = ' '; // Add space after word
            lw_strt = i;
        } else if (i == 0) {
            for (int j = i; j < lw_strt; j++)
                rev_sent[rs_i++] = sent[j];
        }
    }

    // [[ Output ]]
    printf("%s%c\n", rev_sent, term_char);

    return 0;
}

