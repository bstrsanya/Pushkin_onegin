#include "./CompareStr.h"
#include "./SortStr.h"

const int n_str = 5263;

void SortStr (char* n_sent[0])
{
    char* ptr = *(&n_sent[0]);
    for (int i = 0; i < n_str; i ++)
    {
        for (int j = 0; j < n_str-1; j ++)
        {
            if ((CompareStr (n_sent[j], n_sent[j+1])) == 0)
            {
                char* c = n_sent[j];
                n_sent[j] = n_sent[j+1];
                n_sent[j+1] = c;
            }
        }
    }
}