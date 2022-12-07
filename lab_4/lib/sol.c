#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

#define BUFF 4096
#define strip(line) line[strcspn(line, "\n")] = 0
int comp(const void * a, const void * b);

/**
 * @brief: Solve first part of Day 1 in AoC
 * 
 * @param filename: AoC input for my account
 * @return long: Total elf calories
 */
struct solution solve(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        exit(EXIT_FAILURE);

    struct solution sol;
    char line[256];
    int calories[3] = {0, 0, 0};
    int temp_sum = 0;

    while (fgets(line, sizeof(line), file)) {
        if (*line == '\n') {
            swap(&calories[0], &calories[1], &calories[2], temp_sum);
            temp_sum = 0;
        }
        else {
            strip(line);
            temp_sum += atoi(line);
        }
    }
    
    sol.part_one = calories[0];
    sol.part_two = calories[0] + calories[1] + calories[2];

    fclose(file);

    return sol;
}

void swap(int *x, int *y, int *z, int temp_sum)
{
    if (temp_sum > *x) {
        int temp = *x;
        *z = *y;
        *y = temp;
        *x = temp_sum;
    }
    else if (temp_sum > *y) {
        *z = *y;
        *y = temp_sum;
    }
    else if (temp_sum > *z) {
        *z = temp_sum;
    }
}

int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}