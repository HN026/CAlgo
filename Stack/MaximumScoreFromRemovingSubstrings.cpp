#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    int pointsForString(string &s, string &checkString, int points) {
        int maxPoints = 0;
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (st.empty())
                st.push(s[i]);
            else if (st.top() == checkString[0] && s[i] == checkString[1]) {
                maxPoints += points;
                st.pop();
            } else
                st.push(s[i]);
        }
        string temp = "";
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;
        return maxPoints;
    }

    int maximumGain(string s, int x, int y) {
        string s1 = "ab";
        string s2 = "ba";
        if (x < y)
            swap(s1, s2), swap(x, y);
        return pointsForString(s, s1, x) + pointsForString(s, s2, y);
    }
};

int main() {
    Solution solution;
    string s = "cdbcbbaaabab";
    int x = 4, y = 5;
    cout << "Maximum Gain: " << solution.maximumGain(s, x, y) << endl;

    s = "aabbaaxybbaabb";
    x = 5;
    y = 4;
    cout << "Maximum Gain: " << solution.maximumGain(s, x, y) << endl;

    return 0;
}