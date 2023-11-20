#include <iostream>

using namespace std;
unsigned long long int cnt=0;

unsigned long long int mul(int n)
{
    unsigned long long int m = 1;
    for (int i=0; i<n; i++)
        m*=2;
    return m;
}

unsigned long long int hanoi(int n, int a, int b, int c, unsigned long long int k)
{
    if (n == 1){
        cout << a << " " << c << endl;
        return 0;
    }
    
    unsigned long long int tmp = mul(n-1);
    
    if (tmp == k)
        printf("%d %d\n", a, c);
    else if (tmp>k)
        hanoi(n-1, a, c, b, k);
    else{
        hanoi(n-1, b, a, c, k-tmp);
    }
    return 0;
}


int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n;
        unsigned long long int k;
        cin >> n >> k;
        hanoi(n,1,2,3,k);
    }
}