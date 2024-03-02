#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for(int index = 0; index<n; index++){
            for(int prev = 0; prev<index; prev++){
                if(nums[prev]<nums[index]){
                    dp[index] = max(dp[index], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[index]);
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence is: " << length << endl;
    return 0;
}