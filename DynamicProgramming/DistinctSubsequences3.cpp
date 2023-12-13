#include <bits/stdc++.h>

using namespace std;

int distinctSubsequences(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<int> dp(m+1, 0);

    dp[0] = 1;

    for(int i = 1; i<=n; i++){
        vector<int> curr(m+1, 0);
        curr[0] = 1;
        for(int j = 1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                curr[j] = dp[j-1] + dp[j];
            }
            else{
                curr[j] = dp[j];
            }
        }
        dp = curr;
    }
    return dp[m];
}

int main(){
    string s = "rabbbit";
    string t = "rabbit";

    int n = distinctSubsequences(s, t);
    cout<<n<<endl;
    return 0;
}