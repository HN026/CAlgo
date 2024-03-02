#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Solution {
public:
    Node *root;
    string ans;

    Solution() {
        root = new Node();
    }

    void Insert(string word){
        Node *node = root;
        for(char c: word){
            if(!node->containsKey(c)){
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    void dfs(Node *node, string word){
        if(node->isEnd()) {
            if(word.length() > ans.length()){
                ans = word;
            }
        }

        for(char c = 'a'; c<='z'; c++){
            if(node->containsKey(c) && node->get(c)->isEnd()){
                dfs(node->get(c), word+c);
            }
        }
    }


    string longestWord(vector<string>& words) {
        for(string word: words){
            Insert(word);
        }

        dfs(root, "");
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"w","wo","wor","worl", "world"};
    string result = sol.longestWord(words);
    cout << "The longest word is: " << result << endl;
    return 0;
}