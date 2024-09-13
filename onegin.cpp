#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <assert.h>
#include <sys/stat.h>
#include <stdlib.h>


#include "./CompareStr.h"
#include "./SortStr.h"
#include "./CounterStr.h"
#include "./AddrBeginLine.h"
#include "./RecordFile.h"

int main()
{
    // передача данных из файла в одномерный массив
    FILE *file_input = fopen("Text_Onegin.txt", "rb");
    assert (file_input != NULL); //определить размер fseek ftell rewind make-file

    fseek (file_input, 0, SEEK_END);
    size_t file_size = ftell (file_input);
    rewind (file_input);

    char* all_text = (char*) (calloc ((file_size / sizeof (char)) + 1, sizeof (char)));
    fread (all_text, file_size, sizeof (char), file_input);
    fclose (file_input);
    assert (all_text != NULL);
    //

    int n_strock = CounterStr (all_text); // подсчет количества строк в тексте

    char** addr_strock = (char**) (calloc (n_strock, sizeof (char*)));
    addr_strock[0] = all_text;

    AddrBeginLine (all_text, addr_strock); // добавление в массив адресов адрес начала каждой строки    

    SortStr (addr_strock, n_strock); // сортировка строк

    assert (addr_strock != NULL);

    for (int h = 0; h < n_strock; h++)
    {
        assert (addr_strock[h] != NULL);
    }

    RecordFile (addr_strock, n_strock);
    
    free (addr_strock); addr_strock = NULL;
    free (all_text); all_text = NULL;
}










    



    