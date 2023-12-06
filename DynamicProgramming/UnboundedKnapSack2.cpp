#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int n, int maxWeight, vector<int> &weight, vector<int> &profit){
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));
    for(int i = 0; i<=maxWeight; i++){
        dp[0][i] = (i/weight[0])*profit[0];
    }

    for(int index = 1; index<n; index++){
        for(int target = 0; target<=maxWeight; target++){
            int notTake = 0 + dp[index-1][target];
            int take = INT_MIN;
            if(weight[index]<=target) take = profit[index] + dp[index][target - weight[index]];
            dp[index][target] = max(take, notTake);
        }
    }
    return dp[n-1][maxWeight];
}

int main(){
    vector<int> weight = {2,4,6};
    vector<int> profit = {5,11,13};

    int maxWeight = 10;
    int n = weight.size();
    int ans = unboundedKnapsack(n, maxWeight, weight, profit);
    cout<<ans<<endl; 
    return 0;
}