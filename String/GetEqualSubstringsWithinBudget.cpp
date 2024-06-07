#include <iostream>

using namespace std;

class Solution {
  public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int cost = 0;
        while (right < n) {
            cost += abs(s[right] - t[right]);
            while (left < n && cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

int main() {
    Solution sol = Solution();
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    cout << sol.equalSubstring(s, t, maxCost) << endl;
    return 0;
}