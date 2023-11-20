#include <iostream>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

int findMax(int a[], int left, int right)
{
    int half;
    if (left == right)
        return a[left];
    else
    {
        half = (left+right)/2;
        int leftmax = findMax(a, left, half);
        int rightmax = findMax(a, half+1, right);
        return MAX(leftmax, rightmax);
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    while (k--){
        int n;
        scanf("%d", &n);
        int m[100];
        for (int i=0; i<n; i++)
            scanf("%d", &m[i]);
        printf("%d\n", findMax(m, 0, n-1));
    }
}