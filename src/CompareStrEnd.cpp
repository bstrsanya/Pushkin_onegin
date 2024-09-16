#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include "CompareStrEnd.h"

int CompareStrEnd (char* str_1, char* str_2)
{
    char* begin_str_1 = str_1;
    char* begin_str_2 = str_2;
    for (int len_str_1 = 1; *(str_1 + 1) != '\r'; str_1++)
        len_str_1++;
    for (int len_str_2 = 1; *(str_2 + 1) != '\r'; str_2++)
        len_str_2++;
    while (str_1 != begin_str_1 && str_2 != begin_str_2)
    {
        while (isalpha (*str_1) == 0 && str_1 != begin_str_1)
            str_1--;
        while (isalpha (*str_2) == 0 && str_2 != begin_str_2)
            str_2--;
        if (tolower (*str_1) < tolower (*str_2))
            return 1;
        else if (tolower (*str_1) > tolower (*str_2))
            return 0;
        else if ((tolower (*str_1) == tolower (*str_2)) && (str_1 == begin_str_1 && str_2 == begin_str_2))
            return -1;
        else if ((tolower (*str_1) == tolower (*str_2)) && (str_1 == begin_str_1))
            return 1;
        else if ((tolower (*str_1) == tolower (*str_2)) && (str_2 == begin_str_2))
            return 0;
        str_1--;
        str_2--;
    }
}