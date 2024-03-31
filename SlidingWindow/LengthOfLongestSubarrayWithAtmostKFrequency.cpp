#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0;
        int maxi = 0;
        int cnt = 1;
        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;
            maxi = max(maxi, mp[nums[right]]);
            while (maxi > k) {
                if (nums[right] == nums[left]) {
                    maxi--;
                }
                mp[nums[left]]--;
                left++;
            }
            cnt = max(cnt, right - left + 1);
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int k = 2;
    int result = sol.maxSubarrayLength(nums, k);
    cout << "The maximum subarray length with at most " << k << " frequency is: " << result << endl;
    return 0;
}