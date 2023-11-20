#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd(b, a%b);

}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        int m = gcd(a, b);
        cout << m << endl;
    }

    return 0;
}
