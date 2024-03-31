#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto it: nums){
            nums[abs(it)-1] *= -1;
        }

        for(auto it: nums){
            if(nums[abs(it)-1] > 0){
                ans.push_back(abs(it));
            }
            nums[abs(it)-1] *= -1;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> duplicates = sol.findDuplicates(nums);
    for(int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}