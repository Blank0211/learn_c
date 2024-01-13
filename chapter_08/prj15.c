#include <stdio.h>
#include <ctype.h>

int encrypt(char ch, int shift_amnt) {
    if  (isupper(ch))
        return ((ch - 'A') + shift_amnt) % 26 + 'A';
    else if (islower(ch))
        return ((ch - 'a') + shift_amnt) % 26 + 'a';
    else
        return ch;
}

#define SIZE 81
int main(void) {
    // [[ INPUT ]]
    char msg[SIZE] = {0};
    printf("Enter message to be encrypted: ");
    fgets(msg, SIZE-1, stdin); // "SIZE-1": do not write to last element

    char shift_c[4];
    printf("Enter shift amount: (1-25): ");
    fgets(shift_c, sizeof(shift_c), stdin);
    int shift_amnt;
    if (sscanf(shift_c, "%d", &shift_amnt) < 1) {
        printf("ERROR: sscanf could not read shift_c\n");
        return 0; // Terminate program
    }

    // [[ PROCESS INPUT ]]
    char msg_e[SIZE] = {0}; // msg_encrypted
    for (int i = 0; i < SIZE; i++) {
        msg_e[i] = encrypt(msg[i], shift_amnt);
        if (msg[i] == '\0') break;
    }
    
    // [[ OUTPUT ]]
    printf("Enrypted message: %s\n", msg_e);
    return 0;
}

