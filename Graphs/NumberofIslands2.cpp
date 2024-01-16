#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//DFS

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    for(int drow = -1; drow<=1; drow++){
        for(int dcol = -1; dcol<=1; dcol++){
            int nrow = row + drow;
            int ncol = col + dcol;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
}


int numIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int> (m, 0));

    int cnt = 0;
    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(!vis[row][col] && grid[row][col]==1){
                cnt++;
                dfs(row, col, vis, grid);
            } 
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> grid = {{0,1,1,0}, {0,1,1,0}, {0,0,1,0}, {0,0,0,0}, {1,1,0,1}};

    int n = numIslands(grid);
    cout<<n<<" "<<endl;
    return 0;
}
