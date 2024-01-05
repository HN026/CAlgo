#include <bits/stdc++.h>

using namespace std;

int change(int amount, vector<int> &coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, 0));
    for(int i = 0; i<=amount; i++){
        if(i%coins[0]==0) dp[0][i] = 1;
    }
    for(int index = 1; index<n; index++){
        for(int target = 0; target<=amount; target++){
            int notTake = dp[index-1][target];
            int take = 0;
            if(coins[index]<=target) take = dp[index][target-coins[index]];
            dp[index][target] = take + notTake;
        }
    }
    return dp[n-1][amount];
}

int main(){
    vector<int> coins = {2,3,5};
    int amount = 9;

    int ans = change(amount, coins);
    cout<<ans<<endl;
    return 0;
}