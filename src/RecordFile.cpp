#include "RecordFile.h"
#include <stdlib.h>
#include <stdio.h>

void RecordFile (FILE* file_output, char** addr_strock, int n_strock)
{
    for (int i1 = 0; i1 < n_strock - 1; i1++)
    {
        int i2 = 0;
        while (addr_strock[i1][i2] != '\n' and addr_strock[i1][i2] != EOF)
        {
            if ((32 <= addr_strock[i1][i2] && addr_strock[i1][i2] <= 127) or addr_strock[i1][i2] == '\r')
                fputc (addr_strock[i1][i2], file_output);
            i2++;
        }
    }  
}