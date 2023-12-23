#include <iostream>
#include <vector>

using namespace std;


struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string &word){
            Node *node = root;
            for(int i = 0; i<word.size(); i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }

    bool checkIfPrefixExists(string &word){
        bool fl = true;
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd()==false) return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};



string completeString(vector<string> &word){
    Trie *trie = new Trie();
    for(string w: word){
        trie->insert(w);
    }

    string longestWord = "";

    for(auto it: word){
        if(trie->checkIfPrefixExists(it)){
            if(it.size()>longestWord.size()){
                longestWord = it;
            }
            else if(it.size()==longestWord.size() && it<longestWord){
                longestWord = it;
            }
        }
    }

    if(longestWord=="") return "None";

    return longestWord;
}


int main(){
    vector<string> word = {"n", "ni", "nin", "ninj", "ninja", "ninga"};

    string ans = completeString(word);
    cout<<ans<<endl;
    return 0;
}