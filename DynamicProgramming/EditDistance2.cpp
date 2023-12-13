#include <bits/stdc++.h>

using namespace std;

int EditDistance(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int j = 0; j<=m; j++) dp[0][j] = j;
    for(int i = 0; i<=n; i++) dp[i][0] = i;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{
                int a = 1 + dp[i][j-1]; // Insert
                int b = 1 + dp[i-1][j]; // Delete
                int c = 1 + dp[i-1][j-1]; // Replace

                dp[i][j] = min(a, min(b,c));
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s = "intention";
    string t = "execution";

    int a = EditDistance(s, t);
    cout<<a<<endl;
    return 0;
}