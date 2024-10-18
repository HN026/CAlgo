#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isPossible(vector<vector<int>> &dungeon, int mid) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = mid + dungeon[0][0];
        if (dp[0][0] <= 0)
            return false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    continue;

                long long int up = -1e6;
                long long int left = -1e6;

                if (i > 0)
                    up = dp[i - 1][j] + dungeon[i][j];
                if (j > 0)
                    left = dp[i][j - 1] + dungeon[i][j];

                if (up <= 0)
                    up = -1e6;
                if (left <= 0)
                    left = -1e6;

                dp[i][j] = max(up, left);
            }
        }

        return dp[n - 1][m - 1] <= 0 ? false : true;
    }

    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int s = 1;
        
        
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(dungeon, mid)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << "Minimum initial health points required: " << sol.calculateMinimumHP(dungeon) << endl;
    return 0;
}