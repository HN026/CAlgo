#include <iostream>
#include <vector>
#include <limits.h>

// f(a,b) means the length of LIS starting from index a with previous element w index b;

using namespace std;

int f(int index, int prev, vector<vector<int>> &dp, vector<int> &nums){
    if(index==nums.size()) return 0;
    if(dp[index][prev+1]!=-1) return dp[index][prev+1]; 

    int notTake = 0 + f(index+1, prev, dp, nums);
    int take = INT_MIN;
    if(prev == -1 || nums[index]>nums[prev]){
        take = 1 + f(index+1, index, dp, nums);
    }

    return dp[index][prev+1] = max(take, notTake);
}

int lengthOfLIS(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return f(0, -1, dp, nums);
}


int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int ans = lengthOfLIS(nums);
    cout<<ans<<endl;
    return 0;
}