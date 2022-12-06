#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "io.h"

#define BUFF 1024

void parsefile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (file == NULL)
        exit(EXIT_FAILURE);

    /* While there are lines to read */
    while ((read = getline(&line, &len, file)) != -1)
    {
        printf("%s", line);
        char res[strlen(line)/2];
        printf("First half of string: %s\n", slice(line, res, 0, strlen(line)/2));
        printf("Second half of string: %s\n", slice(line, res, strlen(line)/2, strlen(line)));
    }
    
    fclose(file);
    free(line);
    exit(EXIT_SUCCESS);
}

char* slice(const char *part, char *res, size_t start, size_t end)
{
    return strncpy(res, part + start, end - start);
}