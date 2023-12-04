#include <iostream>
#include <vector>

using namespace std;

int totalSubsets(vector<int> &arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target+1, 0));
    for(int i = 0; i<n; i++) dp[i][0] = 1;
    if(arr[0]<=target) dp[0][arr[0]] = 1;

    for(int index = 1; index<n; index++){
        for(int tar = 1; tar<=target; tar++){
            int notTake = dp[index-1][tar];
            int take = 0;
            if(arr[index]<=tar) take = dp[index-1][tar-arr[index]];
            dp[index][tar] = take + notTake;
        }
    }
    return dp[n-1][target];
}

int main(){
    vector<int> arr = {14,8,7,2};
    int target = 5;

    int ans = totalSubsets(arr, target);
    cout<<ans<<endl;
    return 0;
}