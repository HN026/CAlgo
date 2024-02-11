#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> mp;

  for (auto &str : strs) {
    string key = str;
    sort(key.begin(), key.end());
    mp[key].push_back(str);
  }

  vector<vector<string>> ans;
  for (auto &it : mp) {
    ans.push_back(it.second);
  }

  return ans;
}

int main() {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  vector<vector<string>> result = groupAnagrams(strs);

  cout << "Anagram groups are:" << endl;
  for (const auto &group : result) {
    for (const string &str : group) {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}