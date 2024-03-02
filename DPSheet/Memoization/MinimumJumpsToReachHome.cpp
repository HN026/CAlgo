#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fun(int pos, int a, int b, int x, unordered_map<int,int>& mp, int move, vector<vector<int>>& dp) {
        if(pos == x) {
            return 0;
        }
        if(pos < 0 || pos > 6001 || mp.find(pos) != mp.end()) return 1e9;
        if(dp[pos][move] != -1) return dp[pos][move];
        dp[pos][move] = 1 + fun(pos + a, a, b, x, mp, 0, dp);
        if(move == 0) {
            dp[pos][move] = min(dp[pos][move], 1 + fun(pos - b, a, b, x, mp, 1, dp));
        }
        return dp[pos][move];
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,int> mp;
        for(int i = 0; i < forbidden.size(); i++) {
            mp[forbidden[i]] = 1;
        }
        vector<vector<int>> dp(7001, vector<int>(2, -1));
        int d = fun(0, a, b, x, mp, 0, dp);
        if(d >= 1e7) return -1;
        return d;
    }
};

int main() {
    Solution solution;
    vector<int> forbidden = {14, 4, 18, 1, 15}; // forbidden points
    int a = 3; // forward jump length
    int b = 15; // backward jump length
    int x = 9; // target point

    int result = solution.minimumJumps(forbidden, a, b, x);
    cout << "Minimum jumps: " << result << endl; // Should print: Minimum jumps: 3

    return 0;
}