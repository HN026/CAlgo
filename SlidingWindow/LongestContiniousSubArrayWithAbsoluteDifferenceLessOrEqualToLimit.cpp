#include <iostream>
#include <multiset>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = nums.size();
        int left = 0;
        int maxLen = INT_MIN;
        multiset<int> st;
        for (int right = 0; right < n; right++) {
            st.insert(nums[right]);
            int diff = *st.rbegin() - *st.begin();
            while (left <= right && diff > limit) {
                auto it = st.find(nums[left++]);
                st.erase(it);
                diff = *st.rbegin() - *st.begin();
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    cout << s.longestSubarray(nums, limit) << endl;
    return 0;
}