#include <bits/stdc++.h>

using namespace std;

int f(int index, vector<int> &dp, vector<int> &cost){
    if(index==1 || index==0) return cost[index];

    if(dp[index]!=-1) return dp[index];

    int onestep = cost[index] + f(index-1, dp, cost);
    int twostep = cost[index] + f(index-2, dp, cost);

    return min(onestep, twostep);
}

int minCost(vector<int> &cost){
    cost.push_back(0);
    int n = cost.size();
    vector<int> dp(n, -1);
    return f(n-1, dp, cost);
}

int main(){
    vector<int> cost = {10,15,20};

    int ans = minCost(cost);
    cout<<ans<<endl;

    return 0;
}