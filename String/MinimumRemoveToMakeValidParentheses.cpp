#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')')
                continue;
            if (!st.empty() && s[i] == ')' && st.top().first == '(')
                st.pop();
            else
                st.push({s[i], i});
        }
        vector<bool> mp(n, false);
        while (!st.empty()) {
            auto temp = st.top();
            mp[temp.second] = true;
            st.pop();
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (mp[i] == false)
                ans += s[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "lee(t(c)o)de)";
    string result = sol.minRemoveToMakeValid(s);
    cout << "Result: " << result << endl;
    return 0;
}