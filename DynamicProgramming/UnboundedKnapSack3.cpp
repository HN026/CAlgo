#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int n, int maxWeight, vector<int> &weight, vector<int> &profit){
    vector<int> dp(maxWeight+1, 0);
    for(int i = 0; i<=maxWeight; i++){
        dp[i] = (i/weight[0])*profit[0];
    }

    for(int index = 1; index<n; index++){
        vector<int> curr(maxWeight+1, 0);
        for(int target = 0; target<=maxWeight; target++){
            int notTake = 0 + dp[target];
            int take = INT_MIN;
            if(weight[index]<=target) take = profit[index] + curr[target - weight[index]];
            curr[target] = max(take, notTake);
        }
        dp = curr;
    }
    return dp[maxWeight];
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