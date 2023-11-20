#include <iostream>

using namespace std;

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp; 
}

void permuteString(char *str, int begin, int end)
{
    int i, range = end - begin;
    if (range == 1)
        printf("%s\n", str);
    else
    {
        for (i=0; i<range; i++)
        {
            if (str[begin] > str[begin+i])
                swap(&str[begin], &str[begin+i]);
            permuteString(str, begin+1, end);
            if (str[begin] > str[begin+i])
                swap(&str[begin], &str[begin+i]);
        }
    }
}

void permute(char *str)
{
    permuteString(str, 0, strlen(str));
}

int main()
{
    char k[]="fedcba";
    permute(k);
}