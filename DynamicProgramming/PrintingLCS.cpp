#include <bits/stdc++.h>

using namespace std;

string LongestCommonSubseq(string s, string t){
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    int length = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    length = dp[n][m];
    cout<<length<<endl;
    string ans = "";
    for(int i = 0; i<length; i++){
        ans += '$';
    }
    int i = n; 
    int j = m;
    int index = length-1;
    while(i>0 && j>0) {
        if(s[i-1]==t[j-1]){
            ans[index] = s[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    return ans;
}


int main(){
    string s = "abcde";
    string t = "ace";

    string ans = LongestCommonSubseq(s, t);
    cout<<ans<<endl;
    return 0;
}