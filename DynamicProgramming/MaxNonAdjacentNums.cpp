#include <iostream>
#include <vector>

using namespace std;

// *** Memoization ****
// int f(int idx, vector<int> &nums, vector<int> &dp){
//     if(idx==0) return nums[idx];
//     if(idx<0) return 0;

//     if(dp[idx]!=-1) return dp[idx];

//     int pick = nums[idx] + f(idx-2, nums, dp);
//     int nonpick = 0 + f(idx-1, nums, dp);

//     return dp[idx] = max(pick, nonpick);
// }

// int maxNum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return f(n-1, nums, dp);
// }


// ***** Using Tabulation *******

int maxNum (vector<int> &nums ) {
    int n = nums.size();
    if(n==0) return 0;
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for(int i = 1 ; i<n; i++){
        int pick = nums[i];
        if(i>1) pick += dp[i-2];
        int nonpick = 0 + dp[i-1];
        dp[i] = max(pick, nonpick);
    }
    return dp[n-1];
}

// Space optimzation can be done using prev and prev2

int main(){
    vector<int> nums = {1,2,3,1};
    int ans = maxNum(nums);
    cout<<ans<<endl;
    return 0;
}