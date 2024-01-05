#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(int i, vector<int> &nums, vector<int> &dp){
    if(i==nums.size()-1) return 0;
    if(nums[i]==0) return 1e5;

    int steps = INT_MAX;
    if(dp[i]!=-1) return dp[i];

    for(int index = 1; index<=nums[i]; index++){
        if(index+i>=nums.size()){
            break;
        }
        else{
        int cost = 1 + f(index+i, nums, dp);
        steps = min(steps, cost);
        }
    }

    return dp[i] = steps;
}

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return f(0, nums, dp);
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    int minJumps = jump(nums);
    cout << "Minimum number of jumps to reach the end: " << minJumps << endl;
    return 0;
}