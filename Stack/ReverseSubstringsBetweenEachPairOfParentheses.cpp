#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')') {
                string temp = "";
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for (char c : temp)
                    st.push(c);
            } else
                st.push(s[i]);
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "(abcd)";
    cout << "Input: " << s << endl;
    cout << "Output: " << solution.reverseParentheses(s) << endl;

    s = "(u(love)i)";
    cout << "Input: " << s << endl;
    cout << "Output: " << solution.reverseParentheses(s) << endl;

    s = "(ed(et(oc))el)";
    cout << "Input: " << s << endl;
    cout << "Output: " << solution.reverseParentheses(s) << endl;

    s = "a(bcdefghijkl(mno)p)q";
    cout << "Input: " << s << endl;
    cout << "Output: " << solution.reverseParentheses(s) << endl;

    return 0;
}