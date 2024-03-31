#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    long long countSubarrays(vector<int> &nums, int k) {
        int n = nums.size();
        int maxElement = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxElement = max(maxElement, nums[i]);
        }

        int left = 0;
        long long int ans = 0;
        int count = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == maxElement)
                count++;

            while (count >= k) {
                if (nums[left] == maxElement)
                    count--;
                left++;
                ans += n - right;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 2, 3};
    int k = 2;
    long long result = sol.countSubarrays(nums, k);
    cout << "The number of subarrays where the maximum element appears at least " << k << " times is: " << result << endl;
    return 0;
}