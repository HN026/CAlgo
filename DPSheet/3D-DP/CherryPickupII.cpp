#include <iostream>
#include <vector>

using namespace std;

int f(int row, int colr1, int colr2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(colr1<0 || colr1>=m || colr2<0 || colr2>=m){
        return -1e9;
    }
    if(row==n-1){
        if(colr1==colr2) return grid[row][colr1];
        else return grid[row][colr1] + grid[row][colr2];
    }

    if(dp[row][colr1][colr2]!=-1) return dp[row][colr1][colr2];

    int maxi = -1e9;

    for (int dr1 = -1; dr1<=1; dr1++){
        for(int dr2 = -1; dr2<=1; dr2++){
            int ans;
            if(colr1==colr2){
                ans = grid[row][colr1] + f(row+1, colr1+dr1, colr2+dr2, n, m, grid, dp);
            }
            else {
                ans = grid[row][colr1] + grid[row][colr2] + f(row+1, colr1+dr1, colr2+dr2, n, m, grid, dp);
            }

            maxi = max(maxi, ans);
        }
    }

    return dp[row][colr1][colr2] = maxi;
}

int maxPicks(int n, int m, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (m, -1)));
    return f(0, 0, m-1, n, m, grid, dp);
}

int main(){
    vector<vector<int>> grid = {
        {2,3,1,2},
        {3,4,2,2},
        {5,6,3,5},
    };

    int n = grid.size();
    int m = grid[0].size();

    cout<<maxPicks(n, m, grid);
    return 0;
}