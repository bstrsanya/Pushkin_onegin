#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <assert.h>
#include <sys/stat.h>
#include <stdlib.h>


#include "./CompareStr.h"
#include "./SortStr.h"

int main()
{
    struct stat info;
    FILE *file = fopen("URA.txt", "rb");

    assert (file != NULL); //определить размер fseek ftell rewind make-file
    assert (fstat (fileno(file), &info) != -1);

    char* all_text = (char*) (calloc ((info.st_size / sizeof (char)) + 1, sizeof (char)));

    fread (all_text, info.st_size, sizeof (char), file);
    assert (all_text != NULL);

    int n_strock = 1;
    int i = 0;
    while (all_text[i] != '\0')
        {
        n_strock += (all_text[i] == '\n');
        i++;
        }

    char** addr_strock = (char**) (calloc (n_strock, sizeof (char*)));

    addr_strock[0] = all_text;

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

    SortStr (addr_strock, num_strock);

    assert (addr_strock != NULL);

    for (int h = 0; h < n_strock; h++)
    {
        assert (addr_strock[h] != NULL);
    }

    FILE *file_output = fopen ("testura.txt", "w");


    assert (addr_strock[0] != NULL);
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
    free (addr_strock); addr_strock = NULL;
    free (all_text); all_text = NULL;
        

}










    



    