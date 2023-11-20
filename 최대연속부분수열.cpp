#include <iostream>
#define MAX(a,b) ((a)>(b) ? (a):(b))
using namespace std;

int MCSS(int a[], int left, int right)
{
    if (left == right)
        return a[left];

    int half = (left+right)/2;
    
    int inner_leftmax=0, inner_leftsum=0;
    int inner_rightmax=0, inner_rightsum=0;
    for (int i=half; i>=left; i--){
        inner_leftsum += a[i];
        if (inner_leftmax<inner_leftsum)
            inner_leftmax= inner_leftsum;
    }
    for (int i=half+1; i<=right; i++){
        inner_rightsum += a[i];
        if (inner_rightmax<inner_rightsum)
            inner_rightmax = inner_rightsum;
    }
    int leftmax = MCSS(a, left, half);
    int rightmax = MCSS(a, half+1, right);
    int innermax=inner_leftmax+inner_rightmax;
    return MAX(MAX(leftmax, rightmax),innermax);
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
        int ans = MCSS(m, 0, k-1);
        if (ans>=0)
            printf("%d\n", ans);
    }
    return 0;
}