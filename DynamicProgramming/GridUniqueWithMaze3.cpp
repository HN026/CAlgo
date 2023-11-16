#include <iostream>
#include <vector>

using namespace std;

int countWays(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<int> dp(n, 0);
    for(int i = 0; i<m; i++){
        vector<int> temp(n, 0);
        for(int j = 0; j<n; j++){
            if(grid[i][j]==-1){
                temp[j] = 0;
                continue;
            }
            if(i==0 && j==0){
                temp[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i>0) up = dp[j];
            if(j>0) left = temp[j-1];

            temp[j] = up + left;
        }
        dp = temp;
    }
    return dp[n-1];
}

int main(){
    vector<vector<int>> grid {
        {0,0,0},
        {0,-1,0},
        {0,0,0},
    };

    cout<<"Number of unique ways: "<<countWays(grid)<<endl;
    return 0;
}