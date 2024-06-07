#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int longestPalindrome(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]] += 1;
        }

        int maxLen = 0;
        bool hasOdd = false;
        for (auto it : mp) {
            if (it.second % 2 == 0) {
                maxLen += it.second;
            } else {
                maxLen += it.second - 1;
                hasOdd = true;
            }
        }
        return maxLen + (hasOdd ? 1 : 0);
    }
};

int main() {
    Solution s = Solution();
    cout << s.longestPalindrome("abccccdd") << endl;
    return 0;
}