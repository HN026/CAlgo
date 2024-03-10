#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct compare {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b){
        if(a.first==b.first){
            return a.second > b.second;
        }
        return a.first<b.first;
    }
};

class Solution {
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        int n = words.size();

        for(int i = 0; i<n; i++){
            mp[words[i]]++;
        }

        for(auto &it: mp){
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        
        while(!pq.empty() && k){
            auto it = pq.top();
            pq.pop();
            int freq = it.first;
            ans.push_back(it.second);
            k--;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> result = sol.topKFrequent(words, k);
    for (const auto& word : result) {
        cout << word << " ";
    }
    return 0;
}