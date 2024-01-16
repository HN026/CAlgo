#include <iostream>
#include <vector>

using namespace std;


bool dfs(int row, int col, int index, vector<vector<char>> &board, vector<vector<int>> &vis, string word){
    int len = word.length();
    int n = board.size();
    int m = board[0].size();

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==word[index] && !vis[nrow][ncol]){
            vis[nrow][ncol] = 1;
            if(dfs(nrow, ncol, index+1, board, vis, word)) return true;
            vis[nrow][ncol] = 0;
        }
        else if(index==len) return true;
    }
    return false;
}


bool exists(vector<vector<char>> &board, string word){
    int len = word.size();
    int n = board.size();
    int m = board[0].size();

    if(n==1 && m==1 && len==1 && board[0][0]==word[0]) return true;

    vector<vector<int>> vis(n, vector<int> (m, 0));

    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(dfs(row, col, 0, board, vis, word)) return true;
        }
    }

    return false;
}


int main(){
    vector<vector<char>> Board = {
        {'A', 'B', 'C', 'D'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    string word = "ZDF";
    bool ans = exists(Board, word);
    
    if(ans) cout<<"Exists"<<endl;
    else cout<<"Doesn't Exist"<<endl;
    return 0;
}