#include <bits/stdc++.h>

using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> dp(m, 0);

    for(int i = 0; i<m; i++) dp[i] = matrix[0][i];

    for(int i = 1; i<n; i++){
        vector<int> curr(m, 0);
        for(int j = 0; j<m; j++){
            int up = -1e9;
            int ldiag = -1e9;
            int rdiag = -1e9;

            if(i-1>=0) up = matrix[i][j] + dp[j];
            if(i-1>=0 && j-1>=0) ldiag = matrix[i][j] + dp[j-1];
            if(i-1>=0 && j+1<m) rdiag = matrix[i][j] + dp[j+1];

            curr[j] = max(up, max(ldiag, rdiag));
        }
        dp = curr;
    }
    int maxi = -1e9;
    for(int i = 0; i<m; i++){
        maxi = max(maxi, dp[i]);
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