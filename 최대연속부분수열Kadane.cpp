#include <iostream>

using namespace std;

int MCSS(int a[], int n, int *start, int *end)
{
    int i, j;
    int maxSum = 0, thisSum = 0;
    *start = *end = -1;
    for (i=0, j=0; j<n; j++)
    {
        thisSum += a[j];
        if(thisSum > maxSum)
        {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        else if (thisSum <= 0)
        {
            i = j+1;
            thisSum=0;
        }
    }
    return maxSum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        scanf("%d", &k);
        int m[100];
        for (int i=0; i<k; i++)
            scanf("%d", &m[i]);
        int a, b;
        int ans = MCSS(m, k, &a, &b);
        printf("%d %d %d\n", ans, a, b);
        
    }
    return 0;
}