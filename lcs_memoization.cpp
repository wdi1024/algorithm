#include <iostream>
#include <vector>
#include <string>
#define max(a,b) ((a)>=(b)) ? (a) : (b)
using namespace std;

vector<vector<int>> memo;

int longestCommonSubsequence(string a, string b, int m, int n) {
    // 기저 사례: 둘 중 하나의 문자열이 끝에 도달한 경우
    if (m == 0 || n == 0) {
        return 0;
    }

    // Memoization: 이미 계산한 값이 있다면 그 값을 반환
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    // 현재 문자가 같다면, 현재 문자를 포함시키고 한 길이를 증가시킴
    if (a[m - 1] == b[n - 1]) {
        memo[m][n] = 1 + longestCommonSubsequence(a, b, m - 1, n - 1);
    } else {
        // 현재 문자가 다르다면, 둘 중에 하나를 무시하여 비교
        int option1 = longestCommonSubsequence(a, b, m - 1, n);
        int option2 = longestCommonSubsequence(a, b, m, n - 1);
        memo[m][n] = max(option1, option2);
    }

    return memo[m][n];
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        int m = a.length();
        int n = b.length();

        // Memoization 배열 초기화
        memo.assign(m + 1, vector<int>(n + 1, -1));

        int result = longestCommonSubsequence(a, b, m, n);

        cout << result << endl;
    }
    return 0;
}
