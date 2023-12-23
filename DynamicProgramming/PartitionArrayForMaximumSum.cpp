#include <bits/stdc++.h>

using namespace std;

int f(int i, int k, vector<int> &nums, vector<int> &dp){
    int n = nums.size();
    if(i==n) return 0;

    if(dp[i]!=-1) return dp[i];

    int maxAns = -1e9;
    int maxEle = -1e9;
    int length = 0;
    for(int index = i; index < min(n, i+k); index++){
        length++;
        maxEle = max(maxEle, nums[index]);
        int cost = maxEle*length + f(index+1, k, nums, dp);
        maxAns = max(maxAns, cost);
    }
    return dp[i] = maxAns;
}


int maxSum(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return f(0, k, nums, dp);
}


int main(){
    vector<int> nums = {1,15,7,9,2,5,10};
    int k = 3;

    int ans = maxSum(nums, 3);
    cout<<ans<<endl;
    return 0;
}