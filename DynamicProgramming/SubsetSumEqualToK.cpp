#include <bits/stdc++.h>

using namespace std;

bool f(int index, int target, vector<vector<int>> &dp, vector<int> &arr ){
    if(target==0) return true;
    if(index==0) return arr[index]==target;
    if(dp[index][target]!=-1) return dp[index][target];

    bool notTake = f(index-1, target, dp, arr);
    bool take = false;
    if(arr[index]<=target) take = f(index-1, target-arr[index], dp, arr);
    return dp[index][target] = bool(take | notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return f(n-1, k, dp, arr);
}

int main(){
    int k = 5;
    vector<int> arr = {4,3,2,1};
    int n = arr.size();
    cout<<subsetSumToK(n, k, arr)<<endl;

    return 0;
}