#include <bits/stdc++.h>

using namespace std;

int f(int i, int j,  vector<vector<int>> &dp, string s, string t){
    if(j<0) return 1;
    if(i<0) return 0;

    if(s[i]==t[j]){
        return f(i-1, j-1, dp, s, t) + f(i-1, j, dp, s, t);
    }

    return f(i-1, j, dp, s, t);
}

int distinctSubsequences(string &s, string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(n-1,m-1,dp,s,t);
}

int main(){
    string s = "rabbbit";
    string t = "rabbit";

    int ans = distinctSubsequences(s, t);
    cout<<ans<<endl;
    return 0;
}