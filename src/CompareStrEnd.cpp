#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <assert.h>

#include "CompareStrEnd.h"

int CompareStrEnd (char* str_1, char* str_2, int size_1, int size_2)
{
    assert (str_1  != NULL);
    assert (str_2  != NULL);
    assert (size_1 != 0);
    assert (size_2 != 0);

    char* begin_str_1 = str_1;
    char* begin_str_2 = str_2;

    str_1 = str_1 + size_1 - 2;
    str_2 = str_2 + size_2 - 2;

    while (str_1 != begin_str_1 && str_2 != begin_str_2)
    {
        while (isalpha (*str_1) == 0 && str_1 != begin_str_1)
            str_1--;

        while (isalpha (*str_2) == 0 && str_2 != begin_str_2)
            str_2--;

        char str_1_c = (char) tolower (*str_1);
        char str_2_c = (char) tolower (*str_2);

        if (str_1_c < str_2_c)
            return 1;

        else if (str_1_c > str_2_c)
            return 0;

        else if ((str_1_c == str_2_c) && 
                 (str_1 == begin_str_1 && str_2 == begin_str_2))
            return -1;

        else if ((str_1_c == str_2_c) && (str_1 == begin_str_1))
            return 1;

        else if ((str_1_c == str_2_c) && (str_2 == begin_str_2))
            return 0;

        str_1--;
        str_2--;
    }
    return 0;
}