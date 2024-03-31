#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2)));
        dp[0][0][0] = dp[0][0][1] = grid[0][0];
        for(int i = 1; i < m; i++) dp[i][0][0] = dp[i][0][1] = dp[i-1][0][0] * grid[i][0];
        for(int j = 1; j < n; j++) dp[0][j][0] = dp[0][j][1] = dp[0][j-1][0] * grid[0][j];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] < 0) {
                    dp[i][j][0] = min(grid[i][j] * dp[i-1][j][1], grid[i][j] * dp[i][j-1][1]);
                    dp[i][j][1] = max(grid[i][j] * dp[i-1][j][0], grid[i][j] * dp[i][j-1][0]);
                } else {
                    dp[i][j][0] = min(grid[i][j] * dp[i-1][j][0], grid[i][j] * dp[i][j-1][0]);
                    dp[i][j][1] = max(grid[i][j] * dp[i-1][j][1], grid[i][j] * dp[i][j-1][1]);
                }
            }
        }
        return dp[m-1][n-1][1] < 0 ? -1 : dp[m-1][n-1][1] % MOD;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}};
    int result = sol.maxProductPath(grid);
    cout << "The maximum product path is: " << result << endl;
    return 0;
}

// If the current cell's value is negative, the maximum product is obtained by multiplying the current cell's value with the minimum product of the previous cells, and the minimum product is obtained by multiplying the current cell's value with the maximum product of the previous cells. If the current cell's value is positive, the maximum product is obtained by multiplying the current cell's value with the maximum product of the previous cells, and the minimum product is obtained by multiplying the current cell's value with the minimum product of the previous cells.

// Finally, it returns the maximum product path at the bottom-right cell. If the maximum product path is negative, it returns -1.
