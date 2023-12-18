#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return INT_MAX;

    if(dp[i][j]!=-1) return dp[i][j];

    int up = INT_MAX;
    int left = INT_MAX;

    if(i>0) up = grid[i][j] + f(i-1, j, grid, dp);
    if(j>0) left = grid[i][j] + f(i, j-1, grid, dp);

    return dp[i][j] = min(up, left);
}

int minSum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int> (n, -1));
    return f(m-1, n-1, grid, dp);
}

int main(){
    vector<vector<int>> grid {
        {5, 9, 6},
        {11, 5, 2}
    };

    int ans = minSum(grid);
    cout<<ans<<endl;

    return 0;
}