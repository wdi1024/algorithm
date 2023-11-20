#include <iostream>
#include <cstring>

using namespace std;

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp; 
}

void permuteString(char *str, int begin, int end)
{
    swap(&str[begin], &str[end-1]);
    if (begin+1 < end-1)
        permuteString(str, begin+1, end-1);
}

void permute(char *str)
{
    permuteString(str, 0, strlen(str));
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        char strg[100];
        cin >> strg;
        permute(strg);
        printf("%s\n", strg);
    }
}