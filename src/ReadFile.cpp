#include "ReadFile.h"
#include <stdlib.h>
#include <stdio.h>

char* ReadFile (FILE* file_input)
{
    fseek (file_input, 0, SEEK_END);
    size_t file_size = ftell (file_input);
    rewind (file_input);
    char* all_text = (char*) (calloc ((file_size / sizeof (char)) + 1, sizeof (char)));
    fread (all_text, file_size, sizeof (char), file_input);
    return all_text;
}