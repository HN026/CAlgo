/* Will be doing the space optimised appraoch */
/* We can reverse the given string and use the LCS appraoch to find the longest common subsequence */

#include <bits/stdc++.h>

using namespace std;

int LPS(string s){
    string t = "";
    int n = s.length();
    for(int i = n-1; i>=0; i--){
        t += s[i];
    }
    vector<int> dp(n+1, 0);

    for(int i = 1; i<=n; i++){
        vector<int> cur(n+1, 0);
        for(int j = 1; j<=n; j++){
            if(s[i-1]==t[j-1]) cur[j] = 1 + dp[j-1];
            else cur[j] = max(dp[j], cur[j-1]);
        }
        dp = cur;
    }
    return dp[n];
}
/*babcbab*/
int main(){
    string s = "bbabcbcab";
    int ans = LPS(s);
    cout<<ans<<endl;
    return 0;
}