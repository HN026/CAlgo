#include <iostream>
#include <vector>

using namespace std;

int countWays(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int> (n, -1));

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]==-1){
                dp[i][j] = 0;
                continue;
            }
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}


int main(){
    vector<vector<int>> grid {
        {0,0,0},
        {0,-1,0},
        {0,0,0}
    };

    cout<<"Number of unique ways: "<<countWays(grid)<<endl;
    return 0;
}