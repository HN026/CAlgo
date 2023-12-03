#include <iostream>
#include <vector>

using namespace std;

/*Will work only for positive numbers.*/

bool f(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(!target) return true;
    if(!index) return arr[index]==target;
    if(dp[index][target]!=-1) return dp[index][target];

    bool notTake = f(index-1, target, arr, dp);
    bool take = false;
    if(arr[index]<=target) take = f(index-1, target-arr[index], arr, dp);
    return dp[index][target] = bool (take | notTake);
}

int minSubsetSumDiff(vector<int> &arr, int n){
    int totalSum = 0;
    for(auto it: arr){
        totalSum += it;
    }
    vector<vector<int>> dp(n, vector<int> (totalSum+1, -1));

    for(int i = 0; i<=totalSum; i++){
        bool dummy = f(n-1, i, arr, dp);
    }

    int mini = 1e9;

    for(int i = 0; i<=totalSum; i++){
        if(dp[n-1][i]){
            int diff = abs(i-(totalSum-i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {3, 1, 5, 2, 8}; /*Ans = 1*/
    int n = arr.size();

    int ans = minSubsetSumDiff(arr, n);
    cout<<ans<<endl;
    return 0;
}