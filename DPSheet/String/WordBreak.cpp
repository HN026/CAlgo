#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, bool> mp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        for(int i = 0; i<n; i++){
            mp[wordDict[i]] = true;
        }
        int k = s.size();
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        // dp[0] : 0 Length string is always present in the dictionary and can always be segemented.
        // dp[i] means if the string can be segemented from 0..i-1 and the segemented parts are present in the dictionary.
        for(int i = 1; i<=k; i++){
            for(int j = 0; j<i; j++){
                if(dp[j] && mp.find(s.substr(j, i-j))!=mp.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[k];
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = solution.wordBreak(s, wordDict);
    cout << (result ? "True" : "False") << endl;

    return 0;
}