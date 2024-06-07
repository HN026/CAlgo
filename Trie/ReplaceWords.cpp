#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;

    bool containKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
  private:
    Node *root;

  public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

class Solution {
  public:
    vector<string> split(string &sentence) {
        vector<string> result;
        istringstream stream(sentence);
        string word;
        while (stream >> word)
            result.push_back(word);
        return result;
    }

    string replaceWords(vector<string> &dictionary, string sentence) {
        Trie trie = Trie();
        for (string word : dictionary)
            trie.insert(word);

        vector<string> words = split(sentence);
        string ans = "";
        for (string word : words) {
            string prefix = "";
            for (int i = 0; i < word.size(); i++) {
                prefix += word[i];
                if (trie.search(prefix)) {
                    ans += prefix + " ";
                    break;
                }
            }
            if (!trie.search(prefix))
                ans += word + " ";
        }

        return ans.substr(0, ans.size() - 1);
    }
};

int main() {
    Solution sol = Solution();
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << sol.replaceWords(dictionary, sentence) << endl;
    return 0;
}