#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(auto c: num){
            while(!st.empty() && st.top()>c && k){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k){
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        int i;
        reverse(ans.begin(), ans.end());
        for(i = 0; i<ans.size(); i++) if(ans[i]!='0') break;
        string finalAns = ans.substr(i, ans.size()-i+1);
        return finalAns == "" ? "0" : finalAns;
    }
};

int main(){
    Solution s;
    cout << s.removeKdigits("1432219", 3) << endl;
    cout << s.removeKdigits("10200", 1) << endl;
    cout << s.removeKdigits("10", 2) << endl;
    cout << s.removeKdigits("9", 1) << endl;
    cout << s.removeKdigits("112", 1) << endl;
    cout << s.removeKdigits("1234567890", 9) << endl;
    return 0;
}