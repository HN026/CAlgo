#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[j] <= i) {
                    dp[i] = dp[i] + dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int result = sol.combinationSum4(nums, target);
    cout << "The number of combinations that add up to " << target << " is: " << result << endl;
    return 0;
}