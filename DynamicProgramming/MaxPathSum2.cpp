#include <bits/stdc++.h>

using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int i = 0; i<m; i++) dp[0][i] = matrix[0][i];

    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            int up = -1e9;
            int ldiag = -1e9;
            int rdiag = -1e9;

            if(i-1>=0) up = matrix[i][j] + dp[i-1][j];
            if(i-1>=0 && j-1>=0) ldiag = matrix[i][j] + dp[i-1][j-1];
            if(i-1>=0 && j+1<m) rdiag = matrix[i][j] + dp[i-1][j+1];

            dp[i][j] = max(up, max(ldiag, rdiag));
        }
    }
    int maxi = -1e9;
    for(int i = 0; i<m; i++){
        maxi = max(maxi, dp[n-1][i]);
    }
    return maxi;
}

int main(){
    vector<vector<int>> matrix {
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1}
    };

    int ans = getMaxPathSum(matrix);
    cout<<ans<<endl;
    return 0;
}