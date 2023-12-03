#include <iostream>
#include <vector>

using namespace std;

int minSubsetSumDiff(vector<int> &arr, int n){
    int totalSum = 0; 
    for(auto it: arr){
        totalSum += it;
    }

    vector<bool> dp(totalSum+1, false);
    dp[0] = true;
    dp[arr[0]] = true;

    for(int index = 1; index<n; index++){
        vector<bool> curr(totalSum+1, false);
        curr[0] = true;
        for(int target = 1; target<=totalSum; target++){
            bool notTake = dp[target];
            bool take = false;
            if(arr[index]<=target) take = dp[target-arr[index]];
            curr[target] = bool (take | notTake);
        }
        dp = curr;
    }

    int mini = 1e9;
    for(int i = 0; i<=totalSum; i++){
        if(dp[i]){
            int diff = abs(i - (totalSum-i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {3,1,5,2,8};
    int n = arr.size();

    int ans = minSubsetSumDiff(arr, n);
    cout<<ans<<endl;
    return 0;
}