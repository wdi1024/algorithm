#include <iostream>
#include <cstring>

using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 6;
    else if (n == 4)
        return 24;
    else if (n%5==0){
        int k = n*factorial(n-1);
        while (k%10==0)
            k/=10;
        
        return k;
    }
    else
        return n*factorial(n-1)%10000;
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        int i=0;
        int m = factorial(n);
        cout << m%1000 << endl;
    }

    return 0;
}