// https://www.acmicpc.net/blog/view/28 에 피보나치의 특성 및 구현방법 나와있음

#include <iostream>
#include <map>
using namespace std;
map<int, int> d;
const int mod = 1000;
int fibo(long n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else if (d.count(n) > 0) {
        return d[n];
    } else {
        if (n % 2 == 1) {
            long m = (n+1) / 2;
            int t1 = fibo(m);
            int t2 = fibo(m-1);
            d[n] = (t1*t1 + t2*t2) % mod;
            return d[n];
        } else {
            int m = n/2;
            int t1 = fibo(m-1);
            int t2 = fibo(m);
            d[n] = ((2*t1 + t2)*t2) % mod;
            return d[n];
        }
    }
}

int main() {
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        cout << fibo(n) << endl;
    }
    return 0;
}