#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int up = 0;
                int down = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    down = dp[i][j - 1];

                dp[i][j] = up + down;
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}