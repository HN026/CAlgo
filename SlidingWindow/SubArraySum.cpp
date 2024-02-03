#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int> nums, int target){
    int n = nums.size();
    int preSum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i<n; i++){
        preSum += nums[i];
        int remove = preSum - target;
        cnt += mp[remove];
        mp[preSum] += 1;
    }
    return cnt;
}

int main(){
    vector<int> nums = {0,0,0,0,0};
    int target = 0;

    int ans = subarraySum(nums, target);
    cout<<ans<<endl;
    return 0;
}