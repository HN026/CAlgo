#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int> &coins, int amount){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, 0));
    for(int i = 0; i<=amount; i++){
        if(i%coins[0]==0) dp[0][i] = i/coins[0];
        else dp[0][i] = 1e9;
    }

    for(int index = 1; index<n; index++){
        for(int amt = 0; amt<=amount; amt++){
            int notTake = dp[index-1][amt];
            int take = 1e9;
            if(coins[index]<=amt) take = 1 + dp[index][amt-coins[index]];
            dp[index][amt] = min(take, notTake);
        }
    }
    return dp[n-1][amount]>=1e9? -1 : dp[n-1][amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int ans = coinChange(coins, amount);
    cout << ans << endl;
    return 0;
}