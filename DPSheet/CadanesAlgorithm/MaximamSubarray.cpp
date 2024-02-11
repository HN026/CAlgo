#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int sm = nums[0];

    for(int i = 1; i<n; i++){
        dp[i] = max(nums[i], nums[i] + dp[i-1]);
        sm = max(sm, dp[i]);
    }

    return sm;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = maxSubArray(nums);
    cout << "Maximum subarray sum is: " << maxSum << endl;
    return 0;
}
