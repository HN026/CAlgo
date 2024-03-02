#include <iostream>
#include <vector>
using namespace std;

// dp[i][j] represents the longest increasing path to cell (i,j)
// Memoization Approach

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] > matrix[row][col]) {
                if (dp[nrow][ncol] >= 1 + dp[row][col])
                    continue;
                dp[nrow][ncol] = 1 + dp[row][col];
                dfs(nrow, ncol, matrix, dp);
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, matrix, dp);
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    cout << "Longest increasing path length: " << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}