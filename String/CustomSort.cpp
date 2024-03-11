#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<char, int> mp;

static bool compare(char& a, char& b) {
    if (mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
        return mp[a] < mp[b];
    } else {
        return a < b;
    }
}

class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();

        for (int i = 0; i < n; i++) {
            mp[order[i]] = i;
        }

        sort(s.begin(), s.end(), compare);

        return s;
    }
};

int main() {
    Solution sol;
    string order = "cba";
    string s = "abcd";
    string result = sol.customSortString(order, s);
    cout << result << endl;
    return 0;
}