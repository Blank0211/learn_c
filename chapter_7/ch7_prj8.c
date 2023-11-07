// [[ Chapter 7, Project 8 ]]

#include <stdio.h>
#include <ctype.h>

int abs(int n) { return n < 0 ? -n : n; }

void dep(void) {
    printf("Enter a 12-hour time: ");
    int h, m; char period;
    scanf("%d :%d %c", &h, &m, &period);

    // User time in mins
    int time = h * 60 + m;
    if (toupper(period) == 'P' && h != 12) time += 720; // Add 12 hours 

    // Departure times.
    int d1, d2, d3, d4, d5, d6, d7, d8;
    d1 = abs(480  - time);
    d2 = abs(583  - time);
    d3 = abs(679  - time);
    d4 = abs(767  - time);
    d5 = abs(840  - time);
    d6 = abs(945  - time);
    d7 = abs(1140 - time);
    d8 = abs(1305 - time);

    printf("Closest departure time is ");
    if (time < 173)   printf("9:45 PM, arriving at 11:58 PM"); // if user time < 2:53 AM ...
    else if (d1 < d2) printf("8:00 AM, arriving at 10:16 AM");
    else if (d2 < d3) printf("9:43 AM, arriving at 11:52 AM");
    else if (d3 < d4) printf("11:19 AM, arriving at 1:31 PM");
    else if (d4 < d5) printf("12:47 PM, arriving at 3:00 PM");
    else if (d5 < d6) printf("2:00 PM, arriving at 4:08 PM");
    else if (d6 < d7) printf("3:45 PM, arriving at 5:55 PM");
    else if (d7 < d8) printf("7:00 PM, arriving at 9:20 PM");
    else              printf("9:45 PM, arriving at 11:58 PM");
    printf("\n");
}

int main(void) {
    dep();
    return 0;
}

