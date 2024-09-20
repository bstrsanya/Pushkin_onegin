#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "SortStr.h"

void SortStr (data_str* data, int num_strock, int (* Compare_func)(char* str_1,  char* str_2, 
                                                                   int   size_1, int size_2))
{
    assert (data != NULL);
    assert (num_strock != 0);
    assert (Compare_func != NULL);

    for (int i = 0; i < num_strock; i ++)
    {
        for (int j = 0; j < num_strock-1; j ++)
        {
            if ((Compare_func((char*) data[j].addr_str, (char*) data[j+1].addr_str, 
                              (int) data[j].size_str, (int) data[j+1].size_str)) == 0)
            {
                char* c = data[j].addr_str;
                data[j].addr_str = data[j + 1].addr_str;
                data[j+1].addr_str = c;

                int num = data[j].size_str;
                data[j].size_str = data[j+1].size_str;
                data[j+1].size_str = num; // написать свой своп (есть в жопе) спросить у артема 
            }
        }   
    }
}