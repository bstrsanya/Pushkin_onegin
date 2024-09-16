#include "CounterStr.h"

/**     
 * @brief func - jhsjkfhksdj
 * @return  kfkjdl
 */
int CounterStr (char* all_text)
{
    int n_strock = 1;
    int i = 0;
    while (all_text[i] != '\0')
        {
        n_strock += (all_text[i] == '\n');
        i++;
        }
    return n_strock;
}