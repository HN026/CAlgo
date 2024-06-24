#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
    unordered_map<string, bool> mp;
    vector<string> ans;
public:

    void solve(int pos, string st, string &s){
        if(pos==s.size()){
            ans.push_back(st);
            return;
        }
        st += " ";
        for(int i = pos; i<s.size(); i++){
            string temp = s.substr(pos, i-pos+1);
            if(mp.find(temp)!=mp.end()) solve(i+1, st+temp, s);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict) mp[word] = true;
        string st = "";
        int n = s.size();
        for(int i = 0; i<s.size(); i++){
            string temp = s.substr(0, i+1);
            if(mp.find(temp)!=mp.end()) solve(i+1, temp, s);
        }
        return ans;
    }
};

int main(){
    Solution s = Solution();
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    string s1 = "catsanddog";  
    vector<string> ans = s.wordBreak(s1, wordDict);
    for(auto x: ans) cout<<x<<endl;
    return 0;
}

