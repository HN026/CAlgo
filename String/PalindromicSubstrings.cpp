#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int start, int end, string &s, vector<vector<int>> &dp){
        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        int i = start, j = end;
        while(i < j){
            if(s[i++] != s[j--]){
                dp[start][end] = 0;
                return false;
            }
        }
        dp[start][end] = 1;
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=i; j++){
                if(isPalindrome(j, i, s, dp)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    string s = "abcba";
    int count = sol.countSubstrings(s);
    cout << "Number of palindromic substrings: " << count << endl;
    return 0;
}