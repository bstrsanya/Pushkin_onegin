#include <stdio.h>
#include <assert.h>

#include "ComplationStruct.h"

void ComplationStruct(data_str* data, char* all_text, size_t file_size)
{
    assert (data != NULL);
    assert (all_text != NULL);
    assert (file_size != 0);

    data[0].addr_str = all_text;
    assert (all_text != NULL);
    size_t index = 0;
    size_t num_strock = 1;
    size_t n_symbol = 0;

    while (index < file_size)
        {
        if (all_text[index] == '\n')
            {
            (data[num_strock]).addr_str = all_text + index + 1;
            assert (all_text != NULL);
            (data[num_strock - 1]).size_str = n_symbol;
            num_strock++;
            n_symbol = 0;
            }
        index++;
        n_symbol++;
        }
    assert (all_text != NULL);
    data[num_strock].size_str = n_symbol;
}