#include <bits/stdc++.h>

using namespace std;

int f(int index, int target, vector<vector<int>> &dp, vector<int> &coins){
    if(index==0){
        if(!(target%coins[index])) return 1;
        return 0; 
    }

    if(dp[index][target]!=-1) return dp[index][target];

    int notTake = f(index-1, target, dp, coins);
    int take = 0;
    if(coins[index]<=target) take = f(index, target-coins[index], dp, coins);
    return dp[index][target] = take+notTake;
}

int change(int amount, vector<int> &coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    return f(n-1, amount, dp, coins);
}

int main(){
    vector<int> coins = {2,3,5};
    int amount = 9;

    int ans = change(amount, coins);
    cout<<ans<<endl;
    return 0;
}