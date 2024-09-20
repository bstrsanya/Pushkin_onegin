#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "SizeFile.h"

int SizeFile (FILE* file)
{
    assert (file != NULL);

    fseek (file, 0, SEEK_END);
    size_t file_size = ftell (file);
    rewind (file);
    return file_size;
}