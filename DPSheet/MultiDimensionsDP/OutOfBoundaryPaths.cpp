#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

  public:
    int dfs(int row, int col, int K, int m, int n, vector<vector<vector<int>>> &dp) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return 1;
        if (K == 0)
            return 0;
        if (dp[row][col][K] != -1)
            return dp[row][col][K];

        long long int ways = 0;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            ways += dfs(nrow, ncol, K - 1, m, n, dp) % MOD;
        }

        return dp[row][col][K] = ways % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(startRow, startColumn, maxMove, m, n, dp);
    }
};

int main() {
    Solution sol;
    int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
    cout << "The number of paths is: " << sol.findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}