#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// (TotalSum - (Pi - Pj))%k==0 Logic
// p is added to have the positive counterpart of negative mod if incase totalSum-prefixSum is negative.

class Solution {
  public:
    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size(), totalSum = 0, prefixSum = 0;
        for (auto num : nums)
            totalSum = (totalSum + num) % p;
        if (totalSum % p == 0)
            return 0;
        int ans = n;
        unordered_map<int, int> mp;
        mp[0] = 0;

        for (int i = 0; i < n; i++) {
            prefixSum = (prefixSum + nums[i]) % p;
            int check = (prefixSum - totalSum + p) % p;
            if (mp.find(check) != mp.end())
                ans = min(ans, i + 1 - mp[check]);
            mp[prefixSum] = i + 1;
        }
        return ans == n ? -1 : ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << sol.minSubarray(nums, p) << endl;
    return 0;
}