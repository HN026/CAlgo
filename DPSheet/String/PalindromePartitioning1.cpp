#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isPalindromic(string &s, int st, int e) {
        while (st < e) {
            if (s[st++] != s[e--])
                return false;
        }
        return true;
    }

    void solve(int index, vector<string> &v, string &s, vector<vector<string>> &ans) {
        if (index == s.size()) {
            ans.push_back(v);
            return;
        }

        for (int ind = index; ind < s.size(); ind++) {
            if (isPalindromic(s, index, ind)) {
                v.push_back(s.substr(index, ind - index + 1));
                solve(ind + 1, v, s, ans);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(0, v, s, ans);
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.partition(s);
    for (const auto &v : result) {
        for (const auto &str : v) {
            cout << str << " ";
        }
        cout << "\n";
    }
    return 0;
}