#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int ans = 0;

  public:
    bool isPossible(vector<int> &temp, int k) {
        int n = temp.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (temp[j] - temp[i] == k)
                    return false;
            }
        }
        return true;
    }

    void solve(int index, vector<int> &temp, vector<int> &nums, int k) {
        if (index == nums.size()) {
            if (isPossible(temp, k))
                ans++;
            return;
        }
        // Include
        temp.push_back(nums[index]);
        solve(index + 1, temp, nums, k);
        temp.pop_back();
        // Exclude
        solve(index + 1, temp, nums, k);
    }

    int beautifulSubsets(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        int index = 0;
        solve(index, temp, nums, k);
        return ans - 1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    Solution s;
    cout << "The number of beautiful subsets is: " << s.beautifulSubsets(nums, k) << endl;

    return 0;
}