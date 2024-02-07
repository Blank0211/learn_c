#include <inttypes.h>

// Returns absolute val
int abs(int n);

// Returns "A.M." or "P.M." depending on hour
char *ampm(int hour_24);

// Converts 24-hour time to 12-hour
int to_12h(int hour_24);

// Prints err_num and terminates program
void err_exit(uint8_t err_num);

