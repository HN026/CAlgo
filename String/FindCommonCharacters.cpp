#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
    public: 
        vector<string> commonChars(vector<string> &words){
            vector<int> finalFreq(26, INT_MAX);
            
            for(int i = 0; i<words.size(); i++){
                vector<int> currFreq(26, 0);
                for(auto &c: words[i]) currFreq[c - 'a']++;
                for(char i = 'a'; i<='z'; i++) finalFreq[i - 'a'] = min(finalFreq[i - 'a'], currFreq[i - 'a']);
            }
            
            vector<string> result;
            for(char c = 'a'; c <= 'z'; c++){
                while(finalFreq[c - 'a']--) result.push_back(string(1, c));
            }
            
            return result;
        }
};

int main(){
    
    Solution sol = Solution();
    vector<string> words = {"bella", "label", "roller"};
    vector<string> result = sol.commonChars(words);
    for(auto i : result){
        cout << i << " ";
    }
    cout<<endl;
    return 0;
}