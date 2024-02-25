#include <iostream>
#include <vector>

using namespace std;

void dfs(int row, int col, int &sum, int &maxi, vector<vector<int>> &grid, vector<vector<int>> &vis){
    int n = grid.size();
    int m = grid[0].size();
    sum += grid[row][col];
    maxi = max(sum, maxi);
    vis[row][col] = 1;
    int drow[] = {1, 0, -1, 0};
    int dcol[] = {0, -1, 0, 1};

    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]
        !=0){
            dfs(nrow, ncol, sum, maxi, grid, vis);
        }
    }
}

int findMaxFish(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));

    int maxi = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && grid[i][j]!=0){
                int sum = 0;
                dfs(i, j,sum, maxi, grid, vis);
            }
        }
    }

    return maxi;
}

int main() {
    vector<vector<int>> grid = {{0, 2, 1, 0}, 
                                {0, 1, 0, 1}, 
                                {1, 1, 0, 1}, 
                                {0, 0, 0, 0}};

    int maxFish = findMaxFish(grid);

    cout << "Maximum fish that can be caught: " << maxFish << endl;

    return 0;
}