#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    map<string, int> mp;
    string b;
    vector<vector<string>> ans;

public:
    void dfs(string endWord, vector<string> &seq) {
        if (endWord == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int sz = endWord.size();
        int steps = mp[endWord];

        for (int i = 0; i < sz; i++) {
            char original = endWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                endWord[i] = ch;
                if (mp.find(endWord) != mp.end() && mp[endWord] + 1 == steps) {
                    seq.push_back(endWord);
                    dfs(endWord, seq);
                    seq.pop_back();
                }
            }
            endWord[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        st.erase(beginWord);
        mp[beginWord] = 1;
        int sz = beginWord.size();
        while (!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word) > 0) {
                        q.push(word);
                        mp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        if (mp.find(endWord) != mp.end()) {
            vector<string> sq;
            sq.push_back(endWord);
            dfs(endWord, sq);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    // Call the function
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);

    // Display the result
    cout << "Result:" << endl;
    for (const auto &sequence : result) {
        for (const auto &word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
