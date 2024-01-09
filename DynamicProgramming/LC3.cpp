#include <iostream>
#include <vector>

using namespace std;

int LongestCommonSubseq(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> dp(m+1, 0);

    
    for(int i = 1; i<=n; i++){
        vector<int> curr(m+1, 0);
        for(int j = 1; j<=m; j++){
            if(s[i-1]==t[j-1]) curr[j] = 1+dp[j-1];
            else curr[j] = max(dp[j], curr[j-1]);
        }
        dp = curr;
    }

    return dp[m];
}

int main(){
    string s = "aabcc";
    string t = "aadbbcbcac";

    int ans = LongestCommonSubseq(s, t);
    cout<<ans<<endl;
    return 0;
}