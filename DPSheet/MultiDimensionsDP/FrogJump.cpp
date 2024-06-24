#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool canCross(vector<int> &stones) {
        if (stones[1] != 1)
            return false;

        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);
        int n = stones.size();

        for (int i = 0; i < n; i++) {
            for (auto jump : dp[stones[i]]) {
                for (int step = jump - 1; step <= jump + 1; step++) {
                    if (step > 0 && binary_search(stones.begin(), stones.end(), stones[i] + step)) {
                        dp[stones[i] + step].insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};

int main() {
    Solution sol = Solution();
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << sol.canCross(stones) << endl;
    return 0;
}