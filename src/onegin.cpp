#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "Onegin.h"

int main()
{
    FILE *file_input = fopen("Text_Onegin.txt", "rb");
    assert (file_input != NULL);
    
    // получение массива, который содержит данные из файла
    char* all_text = ReadFile (file_input);     
    
    fclose (file_input);
    assert (all_text != NULL);

    // подсчет количества строк в тексте
    int n_strock = CounterStr (all_text); 

    // создание массива, для хранения указателей на каждую строку текста
    char** addr_strock = (char**) (calloc (n_strock, sizeof (char*)));
    addr_strock[0] = all_text;

    // добавление в массив адресов адрес начала каждой строки
    AddrBeginLine (all_text, addr_strock);     

    FILE *file_output = fopen ("Sort_Text_Onegin.txt", "w");
    assert (file_output != NULL);

    //вывод оригинального текста
    fputs ("\nONEGIN'S ORIGINAL TEXT\n\n", file_output);
    RecordFile (file_output ,addr_strock, n_strock);

    // сортировка строк с начала
    SortStr (addr_strock, n_strock, CompareStrBegin); 
    assert (addr_strock != NULL);
    // вывод острортированного с начала текста в файл
    fputs ("\nTHE TEXT IS SORTED FROM THE BEGINNING\n\n", file_output);
    RecordFile (file_output ,addr_strock, n_strock);

    // сортировка строк с конца
    SortStr (addr_strock, n_strock, CompareStrEnd); 
    assert (addr_strock != NULL);
    // вывод острортированного с конца текста в файл
    fputs ("\nTHE TEXT IS SORTED FROM THE END\n\n", file_output);
    RecordFile (file_output ,addr_strock, n_strock);

    fclose (file_output);

    free (addr_strock); addr_strock = NULL;
    free (all_text); all_text = NULL;
}










    



    