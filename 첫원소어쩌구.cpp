#include <iostream>

using namespace std;
int num[1000];

int MCSS(int a[], int n)
{
    int i, j, len=0;
    int max=1;
    for (i=0, j=0; j<n; j++)
    {
        len++;
        if (a[i] > a[j])
        {
            i = j;
            len=1;
        }
        if(len > max)
        {
            max = len;
        }
    }
    return max;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin     >> n;
        for (int i=0; i<n; i++)
            cin >> num[i];
        cout << MCSS(num, n) << endl;
    }
    return 0;
}