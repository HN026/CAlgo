#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> &price, int length){
    int n = price.size();
    vector<vector<int>> dp(n, vector<int> (length+1, -1));
    for(int i = 0; i<=length; i++)
        dp[0][i] = i*price[0];

    for(int index = 1; index<n; index++){
        for(int target = 0; target<=length; target++){
            int notTake = dp[index-1][target];
            int take = INT_MIN;
            if((index+1)<=target) take = price[index] + dp[index][target-(index+1)];
            dp[index][target] = max(take, notTake);
        }
    }
    return dp[n-1][length];
}

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};
    int length = 5;
    int ans = cutRod(price, length);
    cout<<ans<<endl;
    return 0;
}