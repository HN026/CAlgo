#include <iostream>
#include <vector>

using namespace std;

string LPS(string s){
    int n = s.size();
    int maxLen = 1;
    int start = 0;
    
    vector<vector<int>> dp(n, vector<int> (n, 0));
    // dp[i][j] represents if substring from i to j is palindromic or not.

    for(int i = 0; i<n; i++) dp[i][i] = 1;
    
    // Substring of length 2
    for(int i = 0; i<n-1; i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1;
            maxLen = 2;
            start = i;
        }
    }

    // Substring of length > 2
    for(int k = 3; k<=n; k++){
        for(int i = 0; i<n-k+1; i++){
            int j = i+k-1;
            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j] = 1;

                if(k>maxLen){
                    start = i;
                    maxLen = k;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main(){
    string s = "aaaabbaa";

    string ans = LPS(s);
    cout<<ans<<endl;
    return 0; 
}