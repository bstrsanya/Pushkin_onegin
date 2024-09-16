#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include "CompareStrBegin.h"

int CompareStrBegin (char* str_1, char* str_2)
{
    while (*str_1 != '\r' && *str_2 != '\r')
    {
        while (isalpha (*str_1) == 0 && *(str_1 + 1) != '\r')
            str_1++;
        while (isalpha (*str_2) == 0 && *(str_2 + 1) != '\r')
            str_2++;
        if (tolower (*str_1) < tolower (*str_2))
            return 1;
        else if (tolower (*str_1) > tolower (*str_2))
            return 0;
        else if ((tolower (*str_1) == tolower (*str_2)) && (*(str_1 + 1) == '\r' && *(str_2 + 1) =='\r'))
            return -1;
        else if ((tolower (*str_1) == tolower (*str_2)) && (*(str_1 + 1) == '\r'))
            return 1;
        else if ((tolower (*str_1) == tolower (*str_2)) && (*(str_2 + 1) == '\r'))
            return 0;
        str_1++;
        str_2++;
    }
    // int i = 0;
    // while (str_1[i] != '\0' and str_2[i] != '\0')
    // {
    //     if (isalpha (str_1[i]) and isalpha (str_2[i]))
    //         {
    //             if (tolower(str_1[i]) < tolower(str_2[i]))
    //                 return 1;
    //             else if (tolower(str_1[i]) > tolower(str_2[i]))
    //                 return 0;
    //         }
    //     i++;
    // }
    // return -1;
}