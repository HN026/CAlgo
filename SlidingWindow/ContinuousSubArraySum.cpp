#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int prefixSum = 0;

        unordered_map<int, int> firstOcc;
        firstOcc[0] = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int modK = prefixSum % k;
            if (firstOcc.find(modK) != firstOcc.end()) {
                if (i + 1 - firstOcc[modK] >= 2)
                    return true;
            } else {
                firstOcc[modK] = i + 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << sol.checkSubarraySum(nums, k) << endl;
    return 0;
}