#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid ){
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int drow = -1; drow<=1; drow++){
            for(int dcol = -1; dcol<=1; dcol++){
                int nrow = drow + r;
                int ncol = dcol + c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol] ){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m  = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int> (m,0));
    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(!vis[row][col]  && grid[row][col]==1){
                cnt++;
                bfs(row, col, vis, grid);
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
