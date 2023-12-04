#include <iostream>
#include <vector>

using namespace std;

// arr[i]>=0

int f(int index, int target, vector<vector<int>> &dp, vector<int> &arr){
    if(!index){
        if(target==0 && arr[index]==0) return 2;
        if(target==0 || target==arr[index]) return 1;
        return 0;
    }
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
    vector<int> arr = {1,4,4,5};
    int target = 5;

    int ans = totalSubsets(arr, target);
    cout<<ans<<endl;
    return 0;
}