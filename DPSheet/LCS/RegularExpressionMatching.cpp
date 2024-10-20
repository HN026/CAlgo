#include <iostream>
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
            if(p[j-1]=='*') dp[0][j] = dp[0][j-2]; 
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2]; // Treating it as empty string
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){
                        dp[i][j] = dp[i-1][j] || dp[i][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};

int main(){
    Solution sol;
    string s = "aab";
    string p = "c*a*b";
    cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}