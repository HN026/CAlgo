#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>


/* This algorithm has not been optimised yet. */

using namespace std;

void freqVec(unordered_map<char, int> &mp, vector<int> &f) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (mp.find(ch) != mp.end()) {
            f.push_back(mp[ch]);
        }
    }
}

bool closeStrings(string word1, string word2) {
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    set<char> st;
    vector<int> f1;
    vector<int> f2;
    int n1 = word1.size();
    int n2 = word2.size();

    if (n1 != n2) return false;

    for (int i = 0; i < n1; i++) {
        mp1[word1[i]] += 1;
        st.insert(word1[i]);
    }

    for (int i = 0; i < n2; i++) mp2[word2[i]] += 1;

    for (auto it : st) {
        if (mp2.find(it) == mp2.end()) return false;
    }

    freqVec(mp1, f1);
    freqVec(mp2, f2);

    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());

    return f1 == f2;
}

int main() {
    // Test case 1
    string word1 = "abc";
    string word2 = "bca";

    if (closeStrings(word1, word2)) {
        cout << word1 << " and " << word2 << " are close strings.\n";
    } else {
        cout << word1 << " and " << word2 << " are not close strings.\n";
    }

    // Test case 2
    string word3 = "a";
    string word4 = "b";

    if (closeStrings(word3, word4)) {
        cout << word3 << " and " << word4 << " are close strings.\n";
    } else {
        cout << word3 << " and " << word4 << " are not close strings.\n";
    }

    // Add more test cases as needed

    return 0;
}
