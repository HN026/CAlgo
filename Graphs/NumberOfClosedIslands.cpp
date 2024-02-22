#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && !grid[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0; i<m; i++){
            if(!vis[0][i] && !grid[0][i]){
                dfs(0, i, grid, vis);
            }
            if(!vis[n-1][i] && !grid[n-1][i]){
                dfs(n-1, i, grid, vis);
            }
        }

        for(int i = 0; i<n; i++){
            if(!vis[i][0] && !grid[i][0]){
                dfs(i, 0, grid, vis);
            }
            if(!vis[i][m-1] && !grid[i][m-1]){
                dfs(i, m-1, grid, vis);
            }
        }

        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==0){
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};
    int result = sol.closedIsland(grid);
    cout << "The number of closed islands is: " << result << endl;
    return 0;
}