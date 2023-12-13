#include <bits/stdc++.h>

using namespace std;

int EditDistance(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<int> dp(m+1, 0);

    for(int j = 0; j<=m; j++) dp[j] = j;

    for(int i = 1; i<=n; i++){
        vector<int> curr(m+1, 0);
        curr[0] = i;
        for(int j = 1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                curr[j] = 0 + dp[j-1];
            }
            else{
                int a = 1 + curr[j-1]; // Insert
                int b = 1 + dp[j]; // Delete
                int c = 1 + dp[j-1]; // Replace

                curr[j] = min(a, min(b,c));
            }
        }
        dp = curr;
    }
    return dp[m];
}

int main(){
    string s = "intention";
    string t = "execution";

    int a = EditDistance(s, t);
    cout<<a<<endl;
    return 0;
}