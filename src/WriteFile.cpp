#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "WriteFile.h" 

void WriteFile (FILE* file_output, data_str* data, int n_strock)
{
    assert (file_output != NULL);
    assert (data != NULL);
    assert (n_strock != 0);
    
    for (int j = 0; j < n_strock; j++)
    {
        char* num_str = data[j].addr_str;
        int len = data[j].size_str;
        fwrite (num_str, sizeof (char), len, file_output);
    } 
}       