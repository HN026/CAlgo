#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i<n; i++) dp[i] = nums[i] + dp[i-1];

        long long int maxi = -1;
        for(int i = n-1; i>1; i--){
            if(nums[i]<dp[i-1]){
                maxi = dp[i];
                break;
            }
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 2};
    long long result = sol.largestPerimeter(nums);
    cout << "The largest perimeter is: " << result << endl;
    return 0;
}