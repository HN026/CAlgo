#include <bits/stdc++.h>

using namespace std;

    int f(int i, int j, vector<vector<int>> &dp, vector<int> &nums){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = -1;

        for(int index = i; index<=j; index++){
            int cost = nums[i-1]*nums[index]*nums[j+1] + f(i, index-1, dp, nums) + f(index+1, j, dp, nums);
            maxi = max(maxi, cost);
        }


        return dp[i][j] = maxi;
    }



int maxScore(vector<int> &nums){
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return f(1, n, dp, nums);
}


int main(){
    vector<int> maxCoins = {3,1,5,8};

    int ans = maxScore(maxCoins);
    cout<<ans<<endl;

    return 0;
}