#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minPatches(vector<int> nums, int n) {
        long long int maxNumber = 0;
        int sz = nums.size(), i = 0, patches = 0;
        while (maxNumber < n) {
            if (i < sz && maxNumber + 1 >= nums[i])
                maxNumber += nums[i++];
            else {
                maxNumber += maxNumber + 1;
                patches++;
            }
        }
        return patches;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.minPatches({1, 3}, 6) << endl;
    return 0;
}