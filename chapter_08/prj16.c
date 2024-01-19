#include <stdio.h>
#include <ctype.h>

#define WD_LIMIT 20
int main(void) {
    int alph[26] = {0};
    char c = 0;

    // [[ PROCESS INPUT ]]
    printf("Enter 1st word: ");
    for (int i = 0; i < WD_LIMIT; i++) {
        c = getchar();
        if (c == '\n') break;
        if (!isalpha(c)) continue;

        c = tolower(c);
        alph[c-'a']++;
    }

    printf("Enter 2nd word: ");
    for (int i = 0; i < WD_LIMIT; i++) {
        c = getchar();
        if (c == '\n') break;
        if (!isalpha(c)) continue;

        c = tolower(c);
        alph[c-'a']--;
    }
    
    // [[ OUTPUT ]]
    int l = 0;
    for (l = 0; l < 26; l++) {
        if (alph[l] != 0) break;
    }
    if (l < 26)
        printf("The words are not anagrams.\n");
    else
        printf("The words are anagrams.\n");

    return 0;
}

