#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

  public:
    void dfs(int row, int col, vector<vector<int>> &newGrid, vector<vector<int>> &vis, int n) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && newGrid[nrow][ncol] == 0) {
                dfs(nrow, ncol, newGrid, vis, n);
            }
        }
    }

    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();

        vector<vector<int>> newGrid(n * 3, vector<int>(n * 3, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    newGrid[i * 3][j * 3 + 2] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    newGrid[i * 3][j * 3] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int count = 0;
        vector<vector<int>> vis(n * 3, vector<int>(n * 3, 0));
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (newGrid[i][j] == 0 && !vis[i][j]) {
                    count++;
                    dfs(i, j, newGrid, vis, n * 3);
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<string> grid = {
        " /",
        "/ "};

    int result = sol.regionsBySlashes(grid);
    cout << "Number of regions: " << result << endl;

    return 0;
}