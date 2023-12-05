// The problem is Similar to CountPartitionWDifference so I will be directly doing the space optimization method.
// We have been asked to find out the number of ways by which we can assign signs to the numbers in the given set so that the sum becomes equal to the target value which we can easily do by using the login of CountPartitionWDifference logic.

#include <bits/stdc++.h>

using namespace std;

int f(vector<int> &nums, int target){
    int n = nums.size();
    vector<int> dp(target+1, 0);
    if(nums[0]==0) 
        dp[0] = 2;
    else dp[0] = 1;

    if(nums[0]!=0 && nums[0]<=target) dp[nums[0]] = 1;

    for(int i = 1; i<n; i++){
        vector<int> curr(target+1, 0);
        for(int tar = 0; tar<=target; tar++){
            int notTake = dp[tar];
            int take = 0;
            if(nums[i]<=tar) take = dp[tar-nums[i]];
            curr[tar] = take + notTake;
        }
        dp = curr;
    }
    return dp[target];
}


int findTargetSumWays(vector<int> &nums, int target){
    int totalSum = 0;
    for(auto it: nums) totalSum += it;
    if(totalSum-target < 0 || ((totalSum-target)%2) ) return 0;
    return f(nums, (totalSum-target)/2);
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    int ans = findTargetSumWays(nums, target);
    cout<<ans<<endl; 
    return 0;
}