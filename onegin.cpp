#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#include "./CompareStr.h"
#include "./SortStr.h"

const int n_str = 5263;
int main()
{
    FILE *file = fopen("URA.txt", "r");
    char text[n_str][150] = {};    

    for (int yu = 0; yu < n_str; yu++)
        {
        fscanf (file, "%[^\n]", text[yu]);
        fgetc(file);
        }

    char* n_sent[n_str] = {};

    for (int w = 0; w < n_str; w++)
        n_sent[w] = (char*) (text + w);

    SortStr (&n_sent[0]);

    FILE *file2 = fopen ("./testura.txt", "w");

    for (int y = 0; y < n_str; y++)
    {
        fputs (n_sent[y], file2);
        fputs ("\n", file2);
    }

    fclose (file2);  
    fclose(file);
}






    



    