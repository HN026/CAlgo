#include <bits/stdc++.h>

using namespace std;

int change(int amount, vector<int> &coins){
    int n = coins.size();
    vector<int> dp (amount+1, 0);
    for(int i = 0; i<=amount; i++){
        if(i%coins[0]==0) dp[i] = 1;
    }
    for(int index = 1; index<n; index++){
        vector<int> curr(amount+1,0);
        for(int target = 0; target<=amount; target++){
            int notTake = dp[target];
            int take = 0;
            if(coins[index]<=target) take = curr[target-coins[index]];
            curr[target] = take + notTake;
        }
        dp = curr;
    }
    return dp[amount];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;

    int ans = change(amount, coins);
    cout<<ans<<endl;
    return 0;
}