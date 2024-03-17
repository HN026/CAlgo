#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();

        vector<int> hash(2, 0);
        unordered_map<int, int> mp;
        int res = 0;

        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;

            int diff = hash[1] - hash[0];
            if (mp.find(diff) == mp.end()) {
                mp[diff] = i;
            }

            if (hash[1] == hash[0]) {
                res = hash[1] + hash[0];
            } else {
                int idx = mp[diff];
                res = max(res, i - idx);
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    Solution solution;
    int result = solution.findMaxLength(nums);
    cout << result << endl;

    return 0;
}