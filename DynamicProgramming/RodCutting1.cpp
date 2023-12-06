#include <bits/stdc++.h>

using namespace std;

int f(int index, int target, vector<vector<int>>&dp, vector<int> &price){
    if(!index){
        return (target)*price[index];
    }

    if(dp[index][target]!=-1) return dp[index][target];

    int notTake = 0 + f(index-1, target, dp, price);
    int take = INT_MIN;
    if((index+1)<=target) take = price[index] + f(index, target-(index+1), dp, price);
    return dp[index][target] = max(take, notTake);
}

int cutRod(vector<int> &price, int length){
    int n = price.size();
    vector<vector<int>> dp(n, vector<int> (length+1, -1));
    return f(n-1, length, dp, price);
}

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};
    int length = 5;
    int ans = cutRod(price, length);
    cout<<ans<<endl;
    return 0;
}