#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aoc.h"

#define AOC_LINE_LEN 7
#define MAX 3
#define strip(line) line[strcspn(line, "\n")] = 0

/**
 * @brief:
 * Open the file by filename argument, read file line by line
 * with fgets standard C lib function, scan file until end of file,
 * if the beginning char encountered 'line' is a '\n' char we know
 * we have a group division. Then we can compare this value with the
 * max sums in 'calories' to sort it implicitly in place. This way we can
 * avoid needing to know the entire buffer size required to store all groupings,
 * and allocating one large array for all of them.
 * For each line that is not a '\n' we simply parse the string to an integer with
 * atoi(), and prior to passing it to this function we remove the final newline char
 * from the string with the function swap() defined as a macro, avoiding undefined behaviour.
 * 
 * @param filename: AoC input for my account
 * @return int *sol
 */
int* solve(const char *filename, int sol[2])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) exit(EXIT_FAILURE);

    int sum = 0;
    char line[AOC_LINE_LEN];
    int calories[MAX] = {0, 0, 0};

    while (fgets(line, sizeof(line), file)) {
        if (*line == '\n') {
            hotswap(&calories[0], &calories[1], &calories[2], sum);
            sum = 0;
        } else strip(line); sum += atoi(line);
    } fclose(file);

    sol[0] = calories[0];
    sol[1] = calories[0] + calories[1] + calories[2];
    return sol;
}

/**
 * @brief: Swap positions of items in array based
 * on new read line from input file.
 * 
 * @param x: calories[0]
 * @param y: calories[1]
 * @param z: calories[2]
 * @param temp_sum
 */
void hotswap(int *x, int *y, int *z, int sum)
{
    if (sum > *x)
    {
        int temp = *x;
        *z = *y;
        *y = temp;
        *x = sum;
    }
    else if (sum > *y)
    {
        *z = *y;
        *y = sum;
    }
    else if (sum > *z) 
        *z = sum;
}