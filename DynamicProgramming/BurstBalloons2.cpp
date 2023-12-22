#include <bits/stdc++.h>

using namespace std;

int maxScore(vector<int> &nums){
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

    for(int i = n; i>=1; i--){
        for(int j = 1; j<=n; j++){
            if(i>j) continue;
            int maxi = -1;
            for(int index = i; index<=j; index++){
                int cost = nums[i-1]*nums[index]*nums[j+1] + dp[i][index-1] + dp[index+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }    
    return dp[1][n]; 
}


int main(){
    vector<int> maxCoins = {3,1,5,8};

    int ans = maxScore(maxCoins);
    cout<<ans<<endl;

    return 0;
}