#include <iostream>

using namespace std;

int rapid_square(int a, int b)
{
    if (b == 0)
        return 1;
    else
        if (b%2==0){
            int y = rapid_square(a, b/2);
            return y*y%1000;
        }
        else{
            int y = rapid_square(a, b/2);
            return a*y*y%1000;
        }
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        int m = rapid_square(a,b);
        cout << m << endl;
    }
}