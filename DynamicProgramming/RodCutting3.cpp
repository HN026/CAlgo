#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> &price, int length){
    int n = price.size();
    vector<int> dp(length+1, 0);
    for(int i = 0; i<=length; i++)
        dp[i] = i*price[0];

    for(int index = 1; index<n; index++){
        vector<int> curr(length+1, 0);
        for(int target = 0; target<=length; target++){
            int notTake = dp[target];
            int take = INT_MIN;
            if((index+1)<=target) take = price[index] + curr[target-(index+1)];
            curr[target] = max(take, notTake);
        }
        dp = curr;
    }
    return dp[length];
}

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};
    int length = 5;
    int ans = cutRod(price, length);
    cout<<ans<<endl;
    return 0;
}