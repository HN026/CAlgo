#include <iostream>
#include <vector>

using namespace std;


void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &enclave){
    vis[row][col] = 1;
    int  n = enclave.size();
    int  m = enclave[0].size();

    int drow[] = {0,1,0, -1};
    int dcol[] = {-1, 0, 1, 0};

    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && !vis[nrow][ncol] && enclave[nrow][ncol]){
            dfs(nrow, ncol, vis, enclave);
        }
    }
}




int solve(vector<vector<int>> &enclave){
    int n = enclave.size();
    int m = enclave[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));

    for(int i = 0; i<m; i++){
        if(!vis[0][i] && enclave[0][i]){
            dfs(0, i, vis, enclave);
        }
        if(!vis[n-1][i] && enclave[n-1][i]){
            dfs(n-1, i, vis, enclave);
        }
    }

    for(int i = 0; i<n; i++){
        if(!vis[i][0] && enclave[i][0]){
            dfs(i, 0, vis, enclave);
        }
        if(!vis[i][m-1] && enclave[i][m-1]){
            dfs(i, m-1, vis, enclave);
        }
    }

    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && enclave[i][j]){
                count++;
            }
        }
    }
    return count;
}




int main(){

    vector<vector<int>> enclave {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    int c = solve(enclave);

    cout<<c<<endl;

    return 0;
}