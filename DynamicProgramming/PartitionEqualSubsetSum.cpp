#include <bits/stdc++.h>

using namespace std;

bool subsetSum(int n, int k, vector<int> &arr){
    vector<bool> dp(k+1, 0);
    dp[arr[0]] = true;

    for(int index = 1; index < n; index++){
        vector<bool> curr(k+1, 0);
        curr[0] = true;
        for(int target = 1; target<=k; target++){
            bool notTake = dp[target];
            bool take = false;
            if(arr[index]<=target) take = dp[target-arr[index]];
            curr[target] = bool(take | notTake);
        }
        dp = curr;
    }
    return dp[k];
}

bool canPartition(vector<int> &arr, int n){
    int sum = 0;
    for(auto it: arr) sum += it;
    if (sum%2!=0) return false;
    return subsetSum(n, sum/2, arr);
}

int main(){
    vector<int> arr = {99,1};
    int n = arr.size();
    cout<<canPartition(arr,n)<<endl;
    return 0;
}