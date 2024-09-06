#include <stdio.h>
#include <ctype.h>

int CompareStr(char* str_1, char* str_2);

int main()
{
    char text[14][50] = {"My uncle has the most honest rules",
                         "When he was seriously ill,",
                         "He forced himself to respect himself",
                         "And I couldn't have invented a better one",
                         "His example to others is science",
                         "But, my God, what a bore",
                         "Sitting with a patient day and night",
                         "Not taking a step away",
                         "What low cunning",
                         "Half-dead to amuse",
                         "To fix his pillows",
                         "It's sad to bring medicine",
                         "Sigh and think to yourself",
                         "When the devil will take you",
                         };

    char* n_sent[14] = {};

    for (int w = 0; w < 14; w++)
        n_sent[w] = (char*) (text + w);

    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (CompareStr ((char*) n_sent[j], (char*) n_sent[j+1]) == 0)
                {
                    char* c = (char*) n_sent[j];
                    n_sent[j] = n_sent[j+1];
                    n_sent[j+1] = (char*) c;
                }
        }
    }

    for (int y = 0; y < 14; y++)
        puts (n_sent[y]);  
}

int CompareStr(char* str_1, char* str_2)
{
    int i = 0;
    while (str_1[i] != '\0' and str_2[i] != '\0')
    {
        if (isalpha (str_1[i]) and isalpha (str_2[i]))
            {
                if (str_1[i] > str_2[i])
                    return 0;
                else if (str_1[i] < str_2[i])
                    return 1;
            }
        i++;
    }
    return -1;
}



    