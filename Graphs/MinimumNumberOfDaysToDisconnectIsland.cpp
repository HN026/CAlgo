#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

  public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    int countIslands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    islands++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = countIslands(grid);
        if (islands != 1)
            return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int a = countIslands(grid);
                    if (a != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0}};

    int result = sol.minDays(grid);
    cout << "Minimum number of days to disconnect the island: " << result << endl;

    return 0;
}