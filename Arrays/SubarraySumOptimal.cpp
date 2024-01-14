#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int NumberOfSubArrays(vector<int> &nums, int k){
    int n = nums.size();
    int preSum = 0, cnt = 0;
    unordered_map<int, int> mp; // (preSum, Occurances till that index);
    mp[0] = 1; // Number of Subarrays to give you 0 can be 1 as empty subarray to be the initial point
    for(int i = 0; i<n; i++){
        preSum += nums[i];
        int remove = preSum - k;
        cnt += mp[remove];
        mp[preSum] += 1;
    }
    return cnt;
}

int main(){
    vector<int> nums = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int ans = NumberOfSubArrays(nums, k);
    cout<<ans<<endl;

    return 0;
}