#include <bits/stdc++.h>

using namespace std;

int f(int index, int target, vector<vector<int>>&dp, vector<int> &weight, vector<int> &profit){
    if(!index){
        return (target/weight[index])*profit[index];
    }

    if(dp[index][target]!=-1) return dp[index][target];

    int notTake = 0 + f(index-1, target, dp, weight, profit);
    int take = INT_MIN;
    if(weight[index]<=target) take = profit[index] + f(index, target-weight[index], dp, weight, profit);
    return dp[index][target] = max(take, notTake);
}

int unboundedKnapsack(int n, int maxWeight, vector<int> &weight, vector<int> &profit){
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    return f(n-1,maxWeight,dp, weight, profit);
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