#include "RecordFile.h"
#include <stdio.h>

void RecordFile (char** addr_strock, int n_strock)
{
    FILE *file_output = fopen ("Sort_Text_Onegin.txt", "w");
    for (int i1 = 0; i1 < n_strock; i1++)
    {
        int i2 = 0;
        while (addr_strock[i1][i2] != '\r')
        {
            fputc (addr_strock[i1][i2], file_output);
            i2++;
        }
        fputc ('\n', file_output);
    }
    fclose (file_output);
}