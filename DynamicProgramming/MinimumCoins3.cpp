#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int> &coins, int amount){
    int n = coins.size();
    vector<int> dp (amount+1, 0);
    for(int i = 0; i<=amount; i++){
        if(i%coins[0]==0) dp[i] = i/coins[0];
        else dp[i] = 1e9;
    }

    for(int index = 1; index<n; index++){
        vector<int> curr(amount+1, 0);
        for(int amt = 0; amt<=amount; amt++){
            int notTake = 0 + dp[amt];
            int take = 1e9;
            if(coins[index]<=amt) take = 1 + curr[amt-coins[index]];
            curr[amt] = min(take, notTake);
        }
        dp = curr;
    }
    return dp[amount]>=1e9? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int ans = coinChange(coins, amount);
    cout << ans << endl;
    return 0;
}