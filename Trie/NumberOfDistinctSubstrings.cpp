#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }

    Node *get(char ch){
        return links[ch-'a'];
    }


};

int getDistinctSubstrings(string s){
    Node *root = new Node();
    int count = 0;
    int n = s.size();
    for(int i = 0;  i<n; i++){
        Node *node = root;
        for(int j = i; j<n; j++){
            if(!node->containsKey(s[j])){
                count++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }

    return count+1;
}

int main(){
    string s1 = "ababa";
    cout<<getDistinctSubstrings(s1)<<endl;


    string s2 = "ccfdf";
    cout<<getDistinctSubstrings(s2)<<endl;
    return 0;
}