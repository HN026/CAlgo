#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    int n;
    int m;

  public:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid1,
             vector<vector<int>> &grid2, bool &isSubIsland) {
        visited[row][col] = 1;

        if (!grid1[row][col]) {
            isSubIsland = false;
        }

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] &&
                grid2[nrow][ncol]) {
                dfs(nrow, ncol, visited, grid1, grid2, isSubIsland);
            }
        }
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        n = grid1.size();
        m = grid1[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int subGraphs = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid2[i][j]) {
                    bool isSubIsland = true;
                    dfs(i, j, visited, grid1, grid2, isSubIsland);
                    if (isSubIsland) {
                        subGraphs++;
                    }
                }
            }
        }

        return subGraphs;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1}};
    vector<vector<int>> grid2 = {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0}};

    cout << "Number of sub islands: " << solution.countSubIslands(grid1, grid2) << endl;

    return 0;
}