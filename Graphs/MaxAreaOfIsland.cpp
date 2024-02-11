#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, int &area, int &maxArea, vector<vector<int>> &vis, vector<vector<int>> &grid){
    vis[row][col] = 1;
    area++;
    maxArea = max(maxArea, area);

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]
        && grid[nrow][ncol]==1){
            dfs(nrow, ncol, area, maxArea, vis, grid);
        }
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int maxArea = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && grid[i][j]==1){
                int area = 0;
                dfs(i, j, area, maxArea, vis, grid);
            }
        }
    }

    return maxArea;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    cout << "Max area of island is: " << maxAreaOfIsland(grid) << endl;

    return 0;
}