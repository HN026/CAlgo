#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buyOrSell = 0; buyOrSell <= 1; buyOrSell++) {
                if (buyOrSell) {
                    dp[index][buyOrSell] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
                } else {
                    dp[index][buyOrSell] = max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};

int main() {
    Solution solution;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << solution.maxProfit(prices) << endl;
    return 0;
}