#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        if(n<10) return ans;

        unordered_map<string, int> mp;
        int left = 0;
        for(int right = 9; right<n; right++){
            string t = s.substr(left, right-left+1);
            mp[t]++;
            if(mp[t]==2) ans.push_back(t);
            left++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = sol.findRepeatedDnaSequences(s);
    for (const auto& str : result) {
        cout << str << endl;
    }
    return 0;
}