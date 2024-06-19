#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int subarraysDivByK(vector<int> &nums, int k){
            int n = nums.size(), prefixSum = 0, ans = 0;
            unordered_map<int, int> totalOcc;
            totalOcc[0] = 1;
            
            for(int right = 0; right < n; right++){
                prefixSum += nums[right];
                int modK = (prefixSum % k + k) % k;
                ans += totalOcc[modK];
                totalOcc[modK]++;
            }
            
            return ans;
        }
};

int main(){
    Solution s;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << s.subarraysDivByK(nums, k) << endl;
    return 0;
}