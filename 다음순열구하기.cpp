#include <iostream>

using namespace std;

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void FindNextPermutation(char x[], int n)
{
    if (n == 1)
    {
        printf("%c\n", x[0]);
    }
    else
    {
        int i = n - 2;
        while (i >= 0 && x[i] >= x[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = n - 1;
            while (x[i] >= x[j])
                j--;
            swap(&x[i], &x[j]);
        }
        for (int k = i + 1, l = n - 1; k < l; k++, l--)
            swap(&x[k], &x[l]);
        for (int k = 0; k < n; k++)
            printf("%c", x[k]);
        printf("\n");
    }
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        scanf("%d ", &n);
        char m[n];
        for (int i = 0; i < n; i++)
            scanf("%c", &m[i]);
        FindNextPermutation(m, n);
    }
    return 0;
}
