#include "SortStr.h"


void SortStr (char** addr_strock, int num_strock, int (* Compare_func)(char* str_1, char* str_2))
{
    for (int i = 0; i < num_strock; i ++)
    {
        for (int j = 0; j < num_strock-1; j ++)
        {
            if ((Compare_func(addr_strock[j], addr_strock[j+1])) == 0)
            {
                char* c = addr_strock[j];
                addr_strock[j] = addr_strock[j+1];
                addr_strock[j+1] = c;
            }
        }
        
    }
}