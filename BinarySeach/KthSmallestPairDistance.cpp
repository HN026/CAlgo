#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];

        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0, left = 0;

            for (int right = 0; right < n; right++) {
                while (nums[right] - nums[left] > mid) left++;
                count += right - left;
            }

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1};
    int k = 1;

    int result = sol.smallestDistancePair(nums, k);
    cout << "The " << k << "th smallest distance pair is: " << result << endl;

    return 0;
}