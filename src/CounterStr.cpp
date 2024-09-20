#include <assert.h>

#include "CounterStr.h"

int CounterStr (char* all_text, size_t file_size, char c_check)
{
    assert (all_text != NULL);
    assert (file_size != 0);

    size_t n_strock = 0;
    size_t index = 0;
    while (index < file_size)
        {
        n_strock += (all_text[index] == c_check);
        index++;
        }
    return n_strock;
}