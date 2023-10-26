#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>

// Unoptimised Approach

using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList){
    queue<vector<string>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());

    q.push({beginWord});
    vector<string> usedOnLevel;

    usedOnLevel.push_back(beginWord);
    int level = 0;

    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        if(vec.size() > level ){
            level++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
        }
        string word = vec.back();

        if(word==endWord){
            if(ans.size()==0){
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
        }

        for(int i = 0; i<word.size(); i++){
            char original = word[i];
            for(char c = 'a'; c<='z'; c++){
                word[i] = c;
                if(st.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

int main(){
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    vector<vector<string>> ans = findSequences(startWord, targetWord, wordList);

    if(ans.size()==0){
        cout<<-1<<endl;
    }
    else{
        for(int i = 0; i<ans.size(); i++){
            for(int j = 0; j<ans[i].size(); j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}