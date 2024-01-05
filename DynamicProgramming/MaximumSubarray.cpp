// time complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n);
    int maxSum = nums[0];
    dp[0] = nums[0];
    for(int i = 1; i<n; i++){
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = maxSubArray(nums);
    cout << "Maximum subarray sum is: " << maxSum << endl;
    return 0;
}

