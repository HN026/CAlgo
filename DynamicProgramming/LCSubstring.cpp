/* Characters should be consecutive */
#include <bits/stdc++.h>

using namespace std;

// we can space optimize this.

int LCS(string s, string t){
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}

int main(){
    string s = "abcjklp";
    string t = "acjkp";

    int ans = LCS(s, t);
    cout<<ans<<endl;
    return 0;
}