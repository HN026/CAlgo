#include <bits/stdc++.h>

using namespace std;

int f(vector<int> &weight, vector<int> &value, vector<vector<int>> &dp, int index, int maxWeight){
    if(index==0){
        if(weight[index]<=maxWeight)  return value[index];
        else return 0;
    }

    if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];

    int notTake = f(weight, value, dp, index-1, maxWeight);
    int take = INT_MIN;
    if(weight[index]<=maxWeight) take = value[index] + f(weight, value, dp, index-1, maxWeight-weight[index]);
    return dp[index][maxWeight] = max(take, notTake);
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    return f(weight, value, dp, n-1, maxWeight);
}

int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int maxWeight = 5;
    int n = weight.size();
    
    int ans = knapsack(weight, value, n, maxWeight);
    cout<<ans<<endl;
    return 0;
}