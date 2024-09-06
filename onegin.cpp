#include <stdio.h>

int CompareStr(char* str_1, char* str_2);
void ChangeStr(char* str_1, char* str_2);

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

    int* n_sent[14] = {};

    for (int w = 0; w < 14; w++)
        {
        n_sent[w] = (int*) (text + w);
        }

    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (CompareStr ((char*) n_sent[j], (char*) n_sent[j+1]) == 0)
                {
                    int* c = n_sent[j];
                    n_sent[j] = n_sent[j+1];
                    n_sent[j+1] = c;
                }
        }
    }

    for (int y = 0; y < 14; y++)
        {
        int u = 0;
        while (*((int*) (size_t (n_sent[y]) + u * sizeof(char))) != '\0')
        {
            putchar (*((int*) (size_t (n_sent[y]) + u * sizeof(char))));
            u++;
        }
        putchar ('\n');
        }    
}

int CompareStr(char* str_1, char* str_2)
{
    int i = 0;
    while (str_1[i] != '\0' and str_2[i] != '\0')
    {
        if (str_1[i] != ',' and str_1[i] != '-' and str_1[i] != ' ' and
            str_2[i] != ',' and str_2[i] != '-' and str_2[i] != ' ')
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

void ChangeStr(char* str_1, char* str_2)
{
    char change = 0;
    int i = 0;
    while (1)
    {
        change = str_1[i];
        str_1[i] = str_2[i];
        str_2[i] = change;
        i++;
        if (str_1[i] == '\0' and str_2[i] == '\0')
            break;
    }
}

    