#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = nums.size();
        if (k == 0 || k == 1)
            return 0;
        int left = 0;
        unsigned long long int prod = 1;
        int cnt = 0;
        for (int right = 0; right < n; right++) {
            prod *= nums[right];
            while (prod >= k) {
                prod = prod / nums[left];
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}