#include <iostream>
#include <vector>

using namespace std;

// arr[i]>=1

int f(int index, int target, vector<vector<int>> &dp, vector<int> &arr){
    if(target==0) return 1;
    if(index==0) return bool(arr[index]==target);
    if(dp[index][target]!=-1) return dp[index][target];

    int notTake = f(index-1, target, dp, arr);
    int take = 0;
    if(arr[index]<=target) take = f(index-1, target-arr[index], dp, arr);
    return dp[index][target] = take + notTake;
}

int totalSubsets(vector<int> &arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    return f(n-1, target, dp, arr);
}

int main(){
    vector<int> arr = {14,8,7,2};
    int target = 5;

    int ans = totalSubsets(arr, target);
    cout<<ans<<endl;
    return 0;
}