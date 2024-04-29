#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minOperations(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int bit = 0; bit <= 20; bit++) {
            int xorVal = 0;
            for (auto el : nums) {
                int bitVal = (1 << bit) & el;
                xorVal ^= bitVal;
            }

            int KBitVal = (1 << bit) & k;
            if (xorVal != KBitVal)
                ans++;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 6;
    int result = solution.minOperations(nums, k);
    cout << "The minimum number of operations is: " << result << endl;
    return 0;
}