#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const bool compare(const vector<int> &a, const vector<int> &b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

class Solution {
  public:
    int getBestCandidate(map<int, int> &candidates, int num) {
        auto it = candidates.lower_bound(num);
        if (it == candidates.begin())
            return 0;
        it--;
        return it->second;
    }

    void insert(map<int, int> &candidates, int num, int adv) {
        auto it = candidates.lower_bound(num);
        if (it != candidates.end() && it->first == num)
            return;
        it = candidates.insert(it, {num, adv});
        it++;
        while (it != candidates.end() && it->second <= adv) {
            auto temp = it;
            it++;
            candidates.erase(temp);
        }
    }
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        int n = envelopes.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        map<int, int> mp;
        int maxi = 1;
        mp[envelopes[0][1]] = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = 1 + getBestCandidate(mp, envelopes[i][1]);
            insert(mp, envelopes[i][1], dp[i]);
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    int result = solution.maxEnvelopes(envelopes);
    cout << "The maximum number of envelopes you can Russian doll is: " << result << endl;
    return 0;
}