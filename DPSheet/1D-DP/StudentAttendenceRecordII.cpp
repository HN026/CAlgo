#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
    int dp[100001][2][3];

  public:
    long long int solve(int i, int absent, int late) {
        if (i == 0)
            return 1;
        if (dp[i][absent][late] != -1)
            return dp[i][absent][late];

        ll ans = 0;
        ans = (ans + solve(i - 1, absent, 0)) % MOD;
        if (absent < 1)
            ans = (ans + solve(i - 1, absent + 1, 0)) % MOD;
        if (late < 2)
            ans = (ans + solve(i - 1, absent, late + 1)) % MOD;

        return dp[i][absent][late] = ans % MOD;
    }

    int checkRecord(int n) {
        for (int i = 0; i < 100001; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        return solve(n, 0, 0);
    }
};

int main() {
    int n = 10101;
    Solution sol = Solution();
    cout << sol.checkRecord(n) << endl;
    return 0;
}