#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int MinSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int> (n, -1));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i==0 && j==0) {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = INT_MAX;
            int left = INT_MAX;

            if(i>0) up = grid[i][j] + dp[i-1][j];
            if(j>0) left = grid[i][j] + dp[i][j-1];

            dp[i][j] = min(up, left);
        }
    }
    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>> grid {
        {5, 9, 6},
        {11, 5, 2}
    };

    int ans = MinSum(grid);
    cout<<ans<<endl;
    return 0;
}