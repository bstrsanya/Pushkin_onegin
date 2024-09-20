#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <assert.h>

#include "CompareStrBegin.h"

int CompareStrBegin (char* str_1, char* str_2, int size_1, int size_2)
{
    assert (str_1  != NULL);
    assert (str_2  != NULL);
    assert (size_1 != 0);
    assert (size_2 != 0);

    char* end_str_1 = str_1 + size_1;
    char* end_str_2 = str_2 + size_2;

    while (str_1 < end_str_1 - 1 && str_2 < end_str_2)
    {
        while (isalpha (*str_1) == 0 && *(str_1 + 1) != '\r')
            str_1++;

        while (isalpha (*str_2) == 0 && *(str_2 + 1) != '\r')
            str_2++;

        char str_1_c = (char) tolower (*str_1);
        char str_2_c = (char) tolower (*str_2);

        if (str_1_c < str_2_c)
            return 1;

        else if (str_1_c > str_2_c)
            return 0;

        else if ((str_1_c == str_2_c) && 
                 (*(str_1 + 1) == '\r' && *(str_2 + 1) =='\r'))
            return -1;

        else if ((str_1_c == str_2_c) && (*(str_1 + 1) == '\r'))
            return 1;

        else if ((str_1_c == str_2_c) && (*(str_2 + 1) == '\r'))
            return 0;

        str_1++;
        str_2++;
    }
    return 0;
}