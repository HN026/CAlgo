#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;
        for(int j = 1; j<=m; j++){
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2]; // For strings like a*, a*b*, a*b*c*...
        }

        for(int i = 1; i<=n; i++){
            for(int )
        }


    }
};

int main() {
    Solution solution;
    string text = "aa";
    string pattern = "*";
    bool match = solution.isMatch(text, pattern);
    cout << (match ? "true" : "false") << endl;
    return 0;
}