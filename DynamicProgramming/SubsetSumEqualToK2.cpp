#include <bits/stdc++.h>

using namespace std;

// Base case in recursion was when target==0 return true &  *condition 1
// when index==0, if target==arr[0], return true *condition 2
// Now since, dp[index][target]

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    for(int i = 0; i<n; i++) dp[i][0] = true; // condition 1
    dp[0][arr[0]] = true;   // condition 2

    for(int index = 1; index<n; index++){
        for(int target = 1; target<n; target++){
            bool notTake = dp[index-1][target];
            bool take = false;
            if(arr[index]<=target) take = dp[index-1][target-arr[index]];
            dp[index][target] = bool( take | notTake);
        }
    }
    dp[n-1][k];
}

int main(){
    int k = 5;
    vector<int> arr = {4,3,2,1};
    int n = arr.size();
    cout<<subsetSumToK(n, k, arr)<<endl;

    return 0;
}