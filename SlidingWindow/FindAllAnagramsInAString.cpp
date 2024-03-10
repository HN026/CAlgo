#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        vector<int> temp(26, 0);
        vector<int> alpha(26, 0);

        for(int i = 0; i<m; i++){
            alpha[p[i]-'a']++;
        }

        int left = 0;
        for(int right = 0; right<n; right++){
            temp[s[right]-'a']++;
            
            while(right-left+1==m){
                if(temp==alpha){
                    ans.push_back(left);
                }
                temp[s[left]-'a']--;
                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = sol.findAnagrams(s, p);
    for (const auto& num : result) {
        cout << num << " ";
    }
    return 0;
}