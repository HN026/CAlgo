#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board){
    vis[row][col] = 1;
    int n = board.size();
    int m = board[0].size();

    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    
    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
            dfs(nrow, ncol, vis, board);
        }
    }
}   



void solve(vector<vector<char>> &board){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    
    // for first and last row

    for(int i = 0; i<m; i++){
        // first row
        if(!vis[0][i] && board[0][i]=='O'){
            dfs(0, i, vis, board);
        }

        // first col
        if(!vis[n-1][i] && board[n-1][i] == 'O'){
            dfs(n-1, i, vis, board);
        }
    }

    // for first column and last column

    for(int i = 0; i<n; i++){
        // first col
        if(!vis[i][0] && board[i][0]=='O'){
            dfs(i,0,vis, board);
        }
        // Last col
        if(!vis[i][m-1] && board[i][m-1]=='O'){
            dfs(i,m-1,vis, board);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && board[i][j]=='O'){
                board[i][j] ='X';
            }
        }
    }
}





int main(){

    vector<vector<char>> board {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'},
    };

    solve(board);

    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

