#include <inttypes.h>

// Returns absolute value
int abs(int n);

// Returns "A.M." or "P.M." depending on hour
char *ampm(int hour_24);

// Converts 24-hour time to 12-hour
int to_h12(int hour_24);

// Prints "\nERROR_[err_num]" and exits(0) program
void err_exit(uint8_t err_num);

// Gets integer input & assigns it to n on success.
// Sets n to 0, on failure.
// Sets n to INT32_MAX or INT32_MIN, if value is out of range.
// Returns 0 on success, non-zero on failure.
int8_t get_d32(int32_t *n);

