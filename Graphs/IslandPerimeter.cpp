#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>>&vis, vector<pair<int,int>> &perimeter){
    vis[row][col] = 1;
    int drow[] = {1,0,-1,0};
    int dcol[] = {0,-1,0,1};

    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol] && !vis[nrow][ncol]){
            perimeter.push_back({nrow,ncol});
            dfs(nrow,ncol,grid,vis,perimeter);
        }
    }
}

int perimeter(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m,0));
    vector<pair<int, int>> perimeter;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && grid[i][j]){
                perimeter.push_back({i,j});
                dfs(i,j,grid,vis,perimeter);
            }
        }
    }

int p = 0;
int drow[] = {0,1,0,-1};
int dcol[] = {-1,0,1,0};
for(auto it: perimeter){
    for(int i = 0; i<4; i++){
        int nrow = it.first + drow[i];
        int ncol = it.second + dcol[i];

        if(nrow>=n || nrow<0 || ncol>=m || ncol<0 || !grid[nrow][ncol]){
            p++;
        }
    }
}

return p;

}

int main(){
    vector<vector<int>> grid {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    int ans = perimeter(grid);
    cout<<ans<<endl;




    return 0;
}