#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix){
    int k = matrix[0].size();
    if(i==0) return matrix[i][j];
    if(j<0 || j>=k) return -1e9;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = -1e9;
    int ldiagonal = -1e9;
    int rdiagonal = -1e9;

    if(i-1>=0) up = matrix[i][j] + f(i-1, j, dp, matrix);
    if(i-1>=0 && j-1>=0) ldiagonal = matrix[i][j] + f(i-1, j-1, dp, matrix);
    if(i-1>=0 && j+1<k) rdiagonal = matrix[i][j] + f(i-1, j+1, dp, matrix);

    return dp[i][j] = max(up, max(ldiagonal, rdiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    vector<int> ans(m, -1);
    for(int i = 0; i<m; i++){
        ans[i] = f(n-1, i, dp, matrix);
    }
    return *max_element(ans.begin(), ans.end());
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