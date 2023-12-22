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

int totalPartitions(string s){
    int n = s.size();
    vector<int> dp(n+1, 0);

    for(int i = n-1; i>=0; i--){
        int mini = 1e9;
        for(int j = i; j<n; j++){
            if(isPalindrome(s, i, j)){
                int cost = 1 + dp[j+1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    return dp[0]-1;
}

int main(){
    string s = "aab";

    int ans = totalPartitions(s);
    cout<<ans<<endl;

    return 0;
}