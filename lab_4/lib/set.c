#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

char* intersection(const char *x, const char *y, char *buff)
{
    int c = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        for (int j = 0; j < strlen(y); j++)
        {
            if (x[i] == y[j] && !repeated(buff, x[i]))
            {
                buff[c] = x[i];
                c++;
            }
        }
    }
    printf("\n%s\n", buff);
    return buff;
}

int repeated(const char *buff, const char z)
{
    for (int i = 0; i < strlen(buff); i++)
        if (buff[i] == z)
            return 1;
    return 0;
}