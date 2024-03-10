#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int idx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1)
            reverse(nums.begin(), nums.end());

        if (idx != -1) {
            for (int i = n - 1; i > idx; i--) {
                if (nums[idx] < nums[i]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }

            sort(nums.begin() + 1 + idx, nums.end());
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);
    for (const auto &num : nums) {
        cout << num << " ";
    }
    return 0;
}