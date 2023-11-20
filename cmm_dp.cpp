#include <iostream>
#include <climits>
using namespace std;
int dp[101][101];
int P[101][101];
void order(int i, int j)
{
    if (i==j)
        cout <<"M" << i;
    else{
        int k=P[i][j];
        cout <<"(";
        order(i,k);
        order(k+1,j);
        cout << ")";
    }
}

int matrixChainMultiplication(int p[], int n) {
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    P[i][j] = k;
                }
            }
        }
    }
    order(1,n);
    return dp[1][n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int dimensions[n + 1];
        for (int i = 0; i <= n; i++) {
            cin >> dimensions[i];
        }
        int dp[n + 1][n + 1];
        int minCost = matrixChainMultiplication(dimensions, n);
        cout << endl << minCost << endl;
    }
    return 0;
}
