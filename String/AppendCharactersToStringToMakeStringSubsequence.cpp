#include <iostream>

using namespace std;

class Solution {
  public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else
                i++;
        }
        return m - j;
    }
};

int main() {
    Solution sol = Solution();
    string s = "coaching";
    string t = "coding";
    cout << sol.appendCharacters(s, t) << endl;
    return 0;
}