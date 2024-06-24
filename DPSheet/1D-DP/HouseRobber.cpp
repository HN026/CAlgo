#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if(n==0) return 0;
        dp[0] = nums[0];
        for(int i = 1; i<n; i++){
            int take = nums[i];
            if(i>1) take +=  dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }

        return dp[n-1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int result = sol.rob(nums);
    cout << result << endl;
    return 0;
}