#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        vector<int> dp(n, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i<n; i++){
            int onestep = cost[i] + dp[i-1];
            int twostep = cost[i] + dp[i-2];
            dp[i] = min(onestep, twostep);
        }

        return dp[n-1];
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to climb the stairs: " << sol.minCostClimbingStairs(cost) << endl;

    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost to climb the stairs: " << sol.minCostClimbingStairs(cost) << endl;

    return 0;
}