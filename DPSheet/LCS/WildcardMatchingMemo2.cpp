#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1 based indexing

class Solution {
  public:
    bool solve(int i, int j, string &text, string &pattern, vector<vector<int>> &dp) {
        if (i == 0 && j == 0)
            return true;
        if (i > 0 && j == 0)
            return false;
        if (i == 0 && j > 0) {
            for (int ii = 1; ii <= j; ii++)
                if (pattern[ii-1] != '*')
                    return false;
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (text[i-1] == pattern[j-1] || pattern[j-1] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, text, pattern, dp);
        } else if (pattern[j-1] == '*') {
            return dp[i][j] = solve(i, j - 1, text, pattern, dp) | solve(i - 1, j, text, pattern, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, p, dp);
    }
};

int main() {
    Solution solution;
    string text = "aa";
    string pattern = "*";
    bool match = solution.isMatch(text, pattern);
    cout << (match ? "true" : "false") << endl;
    return 0;
}