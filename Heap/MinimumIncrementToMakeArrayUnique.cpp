#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minIncrementForUnique(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                res += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    int res = sol.minIncrementForUnique(nums);
    cout << res << endl;
    return 0;
}