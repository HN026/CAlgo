#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int cur = INT_MIN, ans = 0;
        for (auto &pair : pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << "The length of the longest chain is: " << sol.findLongestChain(pairs) << endl;
    return 0;
}