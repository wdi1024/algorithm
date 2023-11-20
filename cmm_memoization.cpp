#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;
unordered_map<string, int> memo;

int matrixChainMultiplication(int p[], int i, int j) {
    if (i == j) {
        return 0;
    }
    string key = to_string(i) + "_" + to_string(j);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = matrixChainMultiplication(p, i, k) +
                   matrixChainMultiplication(p, k + 1, j) +
                   p[i - 1] * p[k] * p[j];
        if (cost < minCost) {
            minCost = cost;
        }
    }
    memo[key] = minCost;
    return minCost;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int dimensions[n + 1];
        for (int i = 0; i <= n; i++) {
            cin >> dimensions[i];
        }
        memo.clear();
        int minCost = matrixChainMultiplication(dimensions, 1, n);

        cout << minCost << endl;
    }
    return 0;
}
