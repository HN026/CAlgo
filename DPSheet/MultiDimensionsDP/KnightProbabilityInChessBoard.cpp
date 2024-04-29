#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int drow[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dcol[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  public:
    double dfs(int row, int col, int n, int k, vector<vector<vector<double>>> &dp) {
        if (k == 0)
            return 1;
        if (dp[row][col][k] != -1)
            return dp[row][col][k];

        double ways = 0;
        for (int i = 0; i < 8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                ways += dfs(nrow, ncol, n, k - 1, dp);
            }
        }

        return dp[row][col][k] = ways;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        double res = (double)dfs(row, column, n, k, dp);
        for (int i = 0; i < k; i++) {
            res = res / 8;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 3, k = 2, row = 0, column = 0;
    double result = sol.knightProbability(n, k, row, column);
    cout << "The knight's probability to remain on the board is: " << result << endl;
    return 0;
}