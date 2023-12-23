#include <bits/stdc++.h>

using namespace std;

int maxSum(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> dp(n+1, 0);

    for(int i = n-1; i>=0; i--){
        int maxEle = -1e9;
        int length = 0;
        for(int index = i; index<min(n,i+k); index++){
            length++;
            maxEle = max(maxEle, nums[index]);
            int cost = maxEle*length + dp[index+1];
            dp[i] = max(dp[i], cost);
        }
    }

    return dp[0];
}


int main(){
    vector<int> nums = {1,15,7,9,2,5,10};
    int k = 3;

    int ans = maxSum(nums, 3);
    cout<<ans<<endl;
    return 0;
}