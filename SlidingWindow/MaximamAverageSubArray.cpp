#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = INT_MIN;
        int left = 0;
        double sum = 0;
        int length = 0;
        for(int right = 0; right<n; right++){
            sum += nums[right];
            length++;

            while(length==k){
                ans = max(ans, sum/length);
                length--;
                sum -= nums[left];
                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = sol.findMaxAverage(nums, k);
    cout << result << endl;
    return 0;
}