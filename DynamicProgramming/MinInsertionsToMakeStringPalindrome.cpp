    // Longest Palindromic Subsequence (LPS): First, you find the length of the longest palindromic subsequence in the given string. This subsequence is not necessarily contiguous characters, but it is a subsequence that reads the same backward as forward.

    // Minimum Insertions: The minimum number of insertions required to make a string a palindrome is equal to the difference between the length of the original string and the length of its LPS.
    //     Let's say the length of the string is n and the length of the LPS is lps_length. Then, the minimum insertions needed would be n - lps_length.

    // Explanation: The idea is that you can keep the longest palindromic subsequence intact in the center of the palindrome, and you need to insert characters on the sides to make it a complete palindrome.
    //     For example, if the string is "azaa," and the LPS is "aza," you can keep "aza" in the center and add 'a' on both sides to form "aazaa." This makes it a palindrome with the minimum number of insertions (1 insertion in this case).

#include <bits/stdc++.h>

using namespace std;

int makePalindrome(string s){
    string t = "";
    int n = s.size();
    for(int i = n-1; i>=0; i--) t += s[i];

    vector<int> dp(n+1, 0);

    for(int i = 1; i<=n; i++){
        vector<int> curr(n+1, 0);
        for(int j = 1; j<=n; j++){
            if(s[i-1]==t[j-1]) curr[j] = 1 + dp[j-1];
            else curr[j] = max(dp[j], curr[j-1]);
        }
        dp = curr;
    }
    return n - dp[n];
}

int main(){
    string s = "azaa";
    int ans = makePalindrome(s);
    cout<<ans<<endl;
    return 0;
}