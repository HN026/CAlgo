#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int LongestCommonSubseq(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = s[i - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

    int asciSum(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i];
        }
        return sum;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n3 = LongestCommonSubseq(s1, s2);

        int n1 = asciSum(s1);
        int n2 = asciSum(s2);

        return n1 + n2 - 2 * n3;
    }
};

int main() {
    Solution sol;
    string s1 = "sea";
    string s2 = "eat";

    int result = sol.minimumDeleteSum(s1, s2);

    cout << "The minimum ASCII delete sum for two strings is: " << result << endl;

    return 0;
}