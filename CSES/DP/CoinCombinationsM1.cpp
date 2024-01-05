/*https://cses.fi/problemset/task/1635*/

#include <iostream>
#include <vector>

using namespace std;

int f(int target, vector<int> &nums, vector<int> &dp){
    if(target==0) return 1;
    if(target<0) return 0;

    if(dp[target]!=-1) return dp[target];

    int ans = 0;
    for(int i = 0; i<nums.size(); i++){
        ans += f(target-nums[i], nums, dp);
    }
    return dp[target] = ans;
}

int Ways(vector<int> &nums, int target){
    vector<int> dp(target+1, -1);
    return f(target, nums, dp);
}


int main(){
    vector<int> nums = {2,3,5};
    int target = 9;
    int ans = Ways(nums, target);
    cout<<ans<<endl;
    return 0;
}