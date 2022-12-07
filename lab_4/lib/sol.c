#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"
#include "set.h"

#define BUFF 128
#define topriority(x) ((x) >= 'a' && (x) <= 'z' ? (x)-96 : (x)-38)

/**
 * @brief: Solve first part of Day 3 in AoC
 * 
 * @param filename: AoC input for my account
 * @return long: Resulting sum of priorities
 */
long solve_one(const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    long sum = 0;
    size_t len = 0;
    ssize_t read;

    if (file == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, file)) != -1)
    {
        char buff_first[strlen(line)/2];
        char buff_sec[strlen(line)/2];
        char in_buff[BUFF];
        sum += topriority(intersection(slice(line, buff_first, 0, strlen(line)/2), slice(line, buff_sec, strlen(line)/2, strlen(line)), in_buff)[0]);
    }
    
    fclose(file);
    free(line);
    return sum;
}

char* slice(const char *part, char *buff, int start, int end)
{
    int j = 0;
    for (int i = start; i <= end; i++, j++)
        buff[j] = part[i];
    return buff;
}