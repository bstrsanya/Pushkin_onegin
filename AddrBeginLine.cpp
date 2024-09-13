#include "AddrBeginLine.h"

void AddrBeginLine(char* all_text, char** addr_strock)
{
    int j = 0;
    int num_strock = 1;
    while (all_text[j] != '\0')
        {
        if (all_text[j] == '\n')
            {
            addr_strock[num_strock] = all_text + j + 1;
            num_strock++;
            }
        j++;
        }    
}