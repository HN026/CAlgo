#include <iostream>
#include <vector>

using namespace std;

string LPS(string s){
    int n = s.size();

    vector<vector<int>> dp(n, vector<int> (n, 0));
    // dp[i][j] represents substring from i -> j is palindrome or not
    int maxlen = 1;
    
    // For substring length 1
    for(int i = 0; i<n; i++){
        dp[i][i] = 1;
    }

    // For substring length 2
    int start = 0;
    for(int i = 0; i<n-1; i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1;
            start = i;
            maxlen = 2;
        }
    }

    // For K length substring
    for(int k = 3; k<=n; k++){
        for(int i = 0; i<n-k+1; i++){
            int j = i+k-1;
            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j] = 1;

                if(k>maxlen){
                    start = i;
                    maxlen = k;
                }
            }
        }
    }

    string ans = s.substr(start, maxlen);
    return ans;
}   

int main(){
    string s = "aaaabbaa";

    string ans = LPS(s);
    cout<<ans<<endl;
    return 0; 
}