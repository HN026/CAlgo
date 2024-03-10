#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Here dp[i][j] represents the minimum path from the ith row to the last row, if we start from the jth column.
// or we can say dp[i][j] represents the minimum path from the cell (i, j) to the last row.

class Solution {
public:
    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>>&moveCost, vector<vector<int>> &dp){
        if(row+1==grid.size()) return 0;

        if(dp[row][col]!=-1) return dp[row][col];

        int ans = INT_MAX;
        for(int ncol = 0; ncol<grid[0].size(); ncol++){
            int newCost = grid[row+1][ncol] + moveCost[grid[row][col]][ncol];
            ans = min(ans, dfs(row+1, ncol, grid, moveCost,dp)+newCost);
        }

        return dp[row][col] = ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        int ans = INT_MAX;
        for(int col = 0; col<n; col++){
            ans = min(ans, grid[0][col] + dfs(0, col, grid, moveCost, dp));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> moveCost = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = sol.minPathCost(grid, moveCost);
    cout << "Minimum path cost: " << result << endl;
    return 0;
}