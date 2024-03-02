#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isPalindromic(string &s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        for(int i = 0; i<n; i++){
            dp[i] = i;
            for(int j = 0; j<=i; j++){
                if(isPalindromic(s, j, i)){
                    dp[i] = (j==0) ? 0 : min(dp[i], dp[j-1] + 1);
                }
            }
        }

        return dp[n-1];
    }
};

int main() {
    Solution solution;
    string s = "aab";
    int result = solution.minCut(s);
    cout << "Minimum cuts needed for palindrome partitioning are: " << result << endl;

    return 0;
}