#include <iostream>
#include <vector>

using namespace std;

int totalSubsets(vector<int> &arr, int target){
    int n = arr.size();
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    if(arr[0]<=target) dp[arr[0]] = 1;

    for(int index = 1; index<n; index++){
        vector<int> curr(target+1, 0);
        curr[0] = 1;
        for(int tar = 1; tar<=target; tar++){
            int notTake = dp[tar];
            int take = 0;
            if(arr[index]<=tar) take = dp[tar-arr[index]];
            curr[tar] = take + notTake;
        }
        dp = curr;
    }
    return dp[target];
}

int main(){
    vector<int> arr = {1,1,4,5};
    int target = 5;

    int ans = totalSubsets(arr, target);
    cout<<ans<<endl;
    return 0;
}