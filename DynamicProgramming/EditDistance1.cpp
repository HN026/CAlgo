/*
*F(i,j) represents minimum number of operations to convert s[0...i-1] *to t[0...j-1]
*We use insert, delete and replace operation to be t from s
*Insert -> 1 + f(i, j-1);
*Delete -> 1 + f(i-1, j);
*Replace -> 1 + f(i-1, j-1);
*if they are same then there are 0 operations to convert s[0...i-1] to *t[0...j-1]
*base condition. if i<0 then there will be j+1 operations to converty *empty string to t[0...j-1];
*if j<0 then there will be i+1 operations to convert s[0...i-1] to *empty string.
*Time complexity will be exponential before applying dp.
*/

#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, vector<vector<int>> &dp,  string s, string t){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]) return f(i-1, j-1, dp, s, t);

    int a = 1 + f(i, j-1, dp, s, t); //Insert Operation
    int b = 1 + f(i-1, j, dp, s, t); //Delete Operation
    int c = 1 + f(i-1, j-1, dp, s, t); //Replace Operation

    return min(a, min(b,c));
}

int EditDistance(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    return f(n-1,m-1,dp, s, t);
}

int main(){
    string s = "intention";
    string t = "execution";

    int n = EditDistance(s, t);
    cout<<n<<endl;
    return 0;
}