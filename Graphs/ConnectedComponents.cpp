#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    int krow[4] = {-1,0,1,0};
    int kcol[4] = {0,1,0,-1};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++){
            int drow = r + krow[i];
            int dcol = c + kcol[i];
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && !vis[drow][dcol] && grid[drow][dcol]=='1'){
                    vis[drow][dcol] = 1;
                    q.push({drow, dcol});
                }
        }
    }

}


int numIsIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int cnt = 0;
    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(!vis[row][col] && grid[row][col]=='1'){
                cnt++;
                bfs(row, col, grid, vis);
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    int ans = numIsIslands(grid);
    cout<<ans<<endl;
    return 0;
}