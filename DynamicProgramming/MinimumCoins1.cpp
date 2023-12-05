#include <bits/stdc++.h>

using namespace std;

int f(int index, int amount, vector<vector<int>> &dp, vector<int> &coins)
{
    // We are checking index==0 condition not amount==0 because we might even find the minimum coins needed
    // at the last index
    if (index == 0)
    {
        if (amount % coins[index] == 0)
            return amount / coins[index];
        return 1e9;
    }
    if (dp[index][amount] != -1)
        return dp[index][amount];
    int notTake = f(index - 1, amount, dp, coins);
    int take = 1e9;
    if (coins[index] <= amount)
        take = 1 + f(index, amount - coins[index], dp, coins);
    return dp[index][amount] = min(take, notTake);
}

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, amount, dp, coins);
    if (ans >= 1e9)
        return -1;
    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int ans = coinChange(coins, amount);
    cout << ans << endl;
    return 0;
}