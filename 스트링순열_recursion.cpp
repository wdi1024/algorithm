#include <iostream>
#include <string.h>

using namespace std;
#define MAX 10
int cnt=0;

int isminus(int i)
{
    if (i%2==0)
        return 1;
    else
        return -1;
}

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp; 
}

void weight(char* str)
{
    int sum=0;
    for (int i=0; i<strlen(str); i++)
    {
        sum+=(isminus(i)*(str[i]-'a'));
    }
    if (sum>0) cnt++;
}

void permuteString(char *str, int begin, int end)
{
    int i, range = end - begin;
    if (range == 1)
        weight(str);
    else
    {
        for (i=0; i<range; i++)
        {
            swap(&str[begin], &str[begin+i]);
            permuteString(str, begin+1, end);
            swap(&str[begin], &str[begin+i]);
        }
    }
}

void permute(char *str)
{
    permuteString(str, 0, strlen(str));
    printf("%d\n", cnt);
    cnt=0;
}


int main()
{
    int k;
    scanf("%d", &k);
    while (k--)
    {
        char str[MAX];
        cin >> str;
        int sum=0;
        permute(str);

    }
}
