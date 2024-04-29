#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, bool> mp;

  public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        if (s1.length() <= 1 || s1.length() != s2.length())
            return false;

        string key = s1;
        key += ' ';
        key += s2;
        if (mp.find(key) != mp.end())
            return mp[key];
        bool flag = false;
        int n = s1.size();
        for (int i = 1; i < n; i++) {
            // swap -> first condition
            // noswap -> second condition
            if (
                (
                    (
                        isScramble(s1.substr(0, i), s2.substr(n - i, i)) &&
                        isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) ||
                    (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                     isScramble(s1.substr(i, n - i), s2.substr(i, n - i))))) {
                flag = true;
                break;
            }
        }

        return mp[key] = flag;
    }
};

int main() {
    Solution solution;
    string s1 = "great";
    string s2 = "rgeat";
    bool result = solution.isScramble(s1, s2);
    cout << (result ? "Yes" : "No") << endl;
    return 0;
}