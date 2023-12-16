#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n+1, 0);

    for(int index = n-1; index>=0; index--){
        vector<int> curr(n+1, 0);
        for(int prev = index-1; prev>=-1; prev--){
            int notTake = 0 + dp[prev+1]; // here as well we have to shift the dp array
            int take = INT_MIN;
            if(prev==-1 || nums[index]>nums[prev]){
                take = 1 + dp[index+1]; // it is becoming index+1 because we have a shifted dp array.
            }
             curr[prev+1] = max(take, notTake);
        }
        dp = curr;
    }
    return dp[0];
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = lengthOfLIS(nums);
    cout << ans << endl;
    return 0;
}