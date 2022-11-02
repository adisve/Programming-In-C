#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MAX = 5;

    /* Forwards */
    for (int upper_row = 1; upper_row <= MAX; upper_row++) {
        for (int upper_space = 0; upper_space < (MAX - upper_row); upper_space++) {
                printf(" ");
            }
        for (int upper_star = 0; upper_star < upper_row; upper_star++) {
            printf("*");
        }
        putchar('\n');
    }

    /* Backwards */
    for (int lower_row = (MAX - 1); lower_row > 0; lower_row--) {
        for (int lower_space = 0; lower_space < (MAX - lower_row); lower_space++) {
                printf(" ");
            }
        for (int lower_star = 0; lower_star < lower_row; lower_star++) {
            printf("*");
        }
        putchar('\n');
    }
    return 0;
}