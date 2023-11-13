#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n*k)
// Space complexity: O(n)


// ***** Memoization*******
// int f(int idx, int k, vector<int> &height, vector<int> &dp){
//     if(idx==0) return 0;
//     if(dp[idx]!=-1) return dp[idx];
//     int mincost = 1e9;
//     int jump;
//     for(int i = 1; i<=k; i++){
//         if(idx-i>=0){
//             jump = f(idx-i, k, height, dp) + abs(height[idx]-height[idx-i]);
//         }
//         mincost = min(mincost, jump);
//     }
//     return mincost;
// }


// int frogJump(int n, int k, vector<int> &height){
//     vector<int> dp(n, -1);
//     return f(n-1, k, height, dp);
// }


// ******Tabularization********

int frogJump(int n, int k, vector<int> &height){
    vector<int> dp(n, -1);
    for(int i = 1; i<n; i++){
        int mincost = 1e9;
        int jump;
        for(int j = 1; j<=k; j++){
            if(i-j>=0){
                jump = dp[i-j] + abs(height[i]-height[i-j]);
            }
            mincost = min(mincost, jump);
        }
        dp[i] = mincost;
    }
    return dp[n-1];
}

// We can space optimise it using prev and prev2 method since it only depends on the previous two values.

int main(){
    vector<int> height = {10,40,30,10};
    int k = 2;
    int n = height.size();
    int ans = frogJump(n,k,height);
    cout<<ans<<endl;
    return 0;
}