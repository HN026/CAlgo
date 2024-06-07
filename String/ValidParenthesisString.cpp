#include <iostream>

using namespace std;

class Solution {
  public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            low += (c == '(') ? 1 : -1;
            high += (c != ')') ? 1 : -1;
            if (high < 0)
                return false;
            low = max(low, 0);
        }
        return low == 0;
    }
};

int main() {
    string s = ")))";
    Solution sol = Solution();
    cout << sol.checkValidString(s) << endl;
    return 0;
}