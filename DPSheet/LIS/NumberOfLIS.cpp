#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int maxi = 1;
        for(int index = 0; index<n; index++){
            for(int prev = 0; prev<index; prev++){
                if(nums[prev]<nums[index] && dp[index]<1 + dp[prev]){
                    dp[index] = 1 + dp[prev];
                    count[index] = count[prev];
                }
                else if(nums[prev]<nums[index] && dp[index]==1+dp[prev]){
                    count[index] += count[prev];
                }
            }
            maxi = max(dp[index], maxi);
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(dp[i]==maxi){
                ans += count[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    int count = sol.findNumberOfLIS(nums);
    cout << "Number of Longest Increasing Subsequences is: " << count << endl;
    return 0;
}