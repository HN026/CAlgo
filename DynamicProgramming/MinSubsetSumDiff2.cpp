#include <iostream>
#include <vector>

using namespace std;

int minSubsetSumDiff(vector<int> &arr, int n){
    int totalSum = 0;
    for(auto it: arr){
        totalSum += it;
    }

    vector<vector<bool>> dp(n, vector<bool> (totalSum+1, false));
    for(int i = 0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int index = 1; index<n; index++){
        for(int target = 1; target<=totalSum; target++){
            bool notTake = dp[index-1][target];
            bool take = false;
            if(arr[index]<=target) take = dp[index-1][target-arr[index]];
            dp[index][target] = bool (take | notTake);
        }
    }

    int mini = 1e9;
    for(int i = 0; i<=totalSum; i++){
        if(dp[n-1][i]){
            int diff = abs(i - (totalSum-i));
            mini = min(mini, diff);
        }
    }

    return mini;
}

int main(){
    vector<int> arr = {-36,36};
    int n = arr.size();

    int ans = minSubsetSumDiff(arr, n);
    cout<<ans<<endl;
    return 0;
}