#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight){
    vector<int>dp (maxWeight+1, 0);
    // base case as there will be only one object hence all will be of value[0].
    for(int W = weight[0]; W<=maxWeight; W++) dp[W] = value[0]; 

    for(int index = 1; index<n; index++){
        vector<int> curr(maxWeight+1, 0);
        for(int target = 0; target<=maxWeight; target++){
            int notTake = dp[target];
            int take = INT_MIN;
            if(weight[index]<=target) take = value[index] + dp[target-weight[index]];
            curr[target] = max(take, notTake);
        }
        dp = curr;
    }

    return dp[maxWeight];
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