#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int CompareStr(char* str_1, char* str_2);

int main()
{
    const int n_str = 5256;
    
    char text[n_str][150] = {};    

    for (int yu = 0; yu < n_str; yu++)
        {
        scanf ("%[^\n]", text[yu]);
        getchar();
        }

    char* n_sent[n_str] = {};

    for (int w = 0; w < n_str; w++)
        n_sent[w] = (char*) (text + w);

    for (int i = 0; i < n_str; i++)
    {
        for (int j = 0; j < n_str-1; j++)
        {
            if (CompareStr ((char*) n_sent[j], (char*) n_sent[j+1]) == 0)
                {
                    char* c = (char*) n_sent[j];
                    n_sent[j] = n_sent[j+1];
                    n_sent[j+1] = (char*) c;
                }
        }
    }
    for (int y = 0; y < n_str; y++)
        puts (n_sent[y]);  
}

int CompareStr(char* str_1, char* str_2)
{
    int i = 0;
    while (str_1[i] != '\0' and str_2[i] != '\0')
    {
        if (isalpha (str_1[i]) and isalpha (str_2[i]))
            {
                if (tolower(str_1[i]) > tolower(str_2[i]))
                    return 0;
                else if (tolower(str_1[i]) < tolower(str_2[i]))
                    return 1;
            }
        i++;
    }
    return -1;
}

    



    