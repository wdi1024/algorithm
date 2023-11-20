#include <iostream>
#include <climits>

using namespace std;

int matrixChainMultiplication(int p[], int i, int j) {
    if (i == j) {
        return 0; // 한 개의 행렬은 곱셈 비용이 0
    }

    int minCost = INT_MAX;

    // 행렬 곱셈 순서를 바꿔가며 최소 비용 계산
    for (int k = i; k < j; k++) {
        int cost = matrixChainMultiplication(p, i, k) +
                   matrixChainMultiplication(p, k + 1, j) +
                   p[i - 1] * p[k] * p[j];

        if (cost < minCost) {
            minCost = cost;
        }
    }

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

        int minCost = matrixChainMultiplication(dimensions, 1, n);

        cout << minCost << endl;
    }
    return 0;
}
