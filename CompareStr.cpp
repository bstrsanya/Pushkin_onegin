#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include "CompareStr.h"

int CompareStr (char* str_1, char* str_2)
{
    int i = 0;
    while (str_1[i] != '\0' and str_2[i] != '\0')
    {
        if (isalpha (str_1[i]) and isalpha (str_2[i]))
            {
                if (tolower(str_1[i]) > tolower(str_2[i]))
                    return 0;
                else if (tolower(str_1[i]) < tolower(str_2[i]))
                    return 1;
            }
        i++;
    }
    return -1;
}