#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minSum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<int> dp(n, -1);
    for(int i = 0; i<m; i++){
        vector<int> temp(n, -1);
        for(int j = 0; j<n; j++){
            if(i==0&&j==0){
                temp[j] = grid[i][j];
                continue;
            }

            int up = INT_MAX;
            int left = INT_MAX;

            if(i>0) up = grid[i][j] + dp[j];
            if(j>0) left = grid[i][j] + temp[j-1];

            temp[j] = min(up, left);
        }
        dp = temp;
    }

    return dp[n-1];
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