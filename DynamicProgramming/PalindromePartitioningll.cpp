#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string &s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int f(int i, int j, string s, vector<int> &dp){
    if(i==s.size()) return 0;

    if(dp[i]!=-1) return dp[i];

    int mini = 1e9;
    for(int index = i; index<j; index++){
        if(isPalindrome(s, i, index)){
            int cost = 1 + f(index+1, j, s, dp);
            mini = min(mini, cost);
        }
    }

    return dp[i] = mini;
}

int totalPartitions(string s){
    int n = s.size();
    vector<int> dp(n+1, -1);
    return f(0, n, s, dp)-1;
}

int main(){
    string s = "aab";

    int ans = totalPartitions(s);
    cout<<ans<<endl;

    return 0;
}