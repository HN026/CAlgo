#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        vector<int> dp(n + 1, 0);
        dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> testCases = {2, 3, 4, 5, 6, 7, 8, 9, 10, 20};

    cout << "Integer Break Results:" << endl;
    for (int n : testCases) {
        cout << "n = " << n << ": " << solution.integerBreak(n) << endl;
    }

    return 0;
}
