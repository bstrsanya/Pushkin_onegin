#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "Onegin.h"


int main(int argc, char ** argv)
{
    // открытие файла для чтения
    FILE *file_input = fopen (argv[1], "rb");
    if (file_input == NULL) printf ("OPEN FILE ERROR");

    // получение массива, который содержит данные из файла и размера файла
    size_t file_size = 0;
    char* all_text = ReadFile (file_input, &file_size);
    assert (all_text != 0);

    fclose (file_input); 

    // подсчет количества строк в тексте
    int n_strock = CounterStr (all_text, file_size, '\n'); 
    assert (n_strock != 0);

    // создание массива структур, для хранения указателей на каждую строку текста и ее размера
    data_str *data = (data_str *) calloc (n_strock + 1, SIZE_STRUCT_DATA_STR);
    assert (data != 0);
    
    ComplationStruct ((data_str*) data, all_text, file_size);   

    //открытие файла для записи
    FILE *file_output = fopen (argv[2], "wb");
    if (file_output == NULL) printf ("OPEN FILE ERROR");

    //вывод оригинального текста
    fputs ("\nONEGIN'S ORIGINAL TEXT\n\n", file_output);
    WriteFile (file_output , data, n_strock);

    //сортировка строк с начала
    SortStr (data, n_strock, CompareStrBegin); 

    //вывод острортированного с начала текста в файл
    fputs ("\nTHE TEXT IS SORTED FROM THE BEGINNING\n\n", file_output);
    WriteFile (file_output, data, n_strock);

    //сортировка строк с конца
    SortStr (data, n_strock, CompareStrEnd); 

    //вывод острортированного с конца текста в файл
    fputs ("\nTHE TEXT IS SORTED FROM THE END\n\n", file_output);
    WriteFile (file_output, data, n_strock);

    fclose (file_output);

    free (all_text); all_text = NULL;
    free (data); data = NULL;
}    
