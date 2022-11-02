#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_MAX    20

int getnum(char* buffer)
{
    char *p;
    fgets(buffer, sizeof(buffer), stdin);
    return strtol(buffer, &p, 10);
}

void setname(char* buffer)
{
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}