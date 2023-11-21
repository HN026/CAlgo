#include <bits/stdc++.h>

using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> dp(k+1, 0);
    dp[arr[0]] = true;

    for(int index = 1; index<n; index++){
        vector<bool> curr(k+1, 0);
        curr[0] = true;
        for(int target = 1; target<=k; target++){
            bool notTake = dp[target];
            bool take = false;
            if(arr[index]<=target) take = dp[target-arr[index]];
            curr[target] = bool (take | notTake);
        }
        dp = curr;
    }
    return dp[k];
}

int main(){
    int k = 5;
    vector<int> arr = {4,3,2,1};
    int n = arr.size();
    cout<<subsetSumToK(n, k, arr)<<endl;

    return 0;
}