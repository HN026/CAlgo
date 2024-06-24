#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// ****Memoization Approach****
// class Solution {
//     unordered_map<int, int> dp;
// public:

//     int solve(int index, string &s){
//         if(s[index]=='0') return 0;
//         if(index >= s.length()-1) return 1;

//         if(dp.find(index)!=dp.end()) return dp[index];

//         int ans = solve(index+1, s);
//         if(stoi(s.substr(index, 2)) <= 26) ans += solve(index+2, s);

//         return dp[index] = ans;
//     }

//     int numDecodings(string s) {
//         return solve(0, s);
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        dp[0] = 1; // Empty String
        dp[1] = (s[0]=='0') ? 0 : 1;
        
        for(int i = 2; i<=n; i++){
            if(s[i-1]!='0') dp[i] += dp[i-1];

            int num = stoi(s.substr(i-2, 2));
            if(s[i-2]!='0' && num <= 26) dp[i] += dp[i-2];
        }

        return dp[n];
    }
};

int main(){
    Solution s = Solution();
    cout << s.numDecodings("12") << endl;
    return 0;
}