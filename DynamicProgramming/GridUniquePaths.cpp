#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time complexity: At max, there will be O(m*n) calls for recursion.
// Space Complexity: O((n-1)+(m-1)) + O(m*n)

int countWaysUntil(int i, int j, vector<vector<int>> &dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int up = countWaysUntil(i-1, j, dp);
    int left = countWaysUntil(i, j-1,dp);

    return dp[i][j] = up+left;
}

int countWays(int m, int n){
    vector<vector<int>> dp(m, vector<int> (n,-1));
    return countWaysUntil(m-1, n-1, dp);
}

int main(){
    int m = 3; 
    int n = 2;

    cout<<"Numbers of Unique ways to reach would be: "<<countWays(m,n)<<endl;
    return 0;
}