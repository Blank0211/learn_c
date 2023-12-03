// clang % -o a.exe -std=c18 -Wall -Wextra -pedantic -Wformat=2 -g
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define bool _Bool
#define true 1
#define false 0

#define MSG_LEN 80
void biff(void) {
    printf("Enter message: ");
    char msg[MSG_LEN] = {0};
    // Get & store message (until newline)
    for (int i = 0; i < MSG_LEN; i++) {
        msg[i] = getchar();
        if (msg[i] == '\n') break;
    }
    
    // Trasnlate to B1FF-speak
    for (int c = 0; c < MSG_LEN; c++)
        msg[c] = toupper(msg[c]); // Make all chars to uppercase
    // Substitue digits for certain letters 
    for (int c = 0; c < MSG_LEN; c++) {
        switch (msg[c]) {
            case 'A':
                msg[c] = '4'; break;
            case 'B':
                msg[c] = '8'; break;
            case 'E':
                msg[c] = '3'; break;
            case 'I':
                msg[c] = '1'; break;
            case 'O':
                msg[c] = '0'; break;
            case 'S':
                msg[c] = '5'; break;
            default:
                break;
        }
    }

    // Display message
    printf("In B1FF-speak: ");
    for (int i = 0; i < MSG_LEN; i++) {
        if (msg[i] == '\n') break;
        printf("%c", msg[i]);
    } printf("!!!!!!!!!\n"); // Append exclamation marks
}

int main(void) {
    biff();
    return 0;
}

