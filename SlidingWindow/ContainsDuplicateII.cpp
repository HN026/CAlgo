#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if(mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k){
            return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};
    int k = 3;
    bool result = containsNearbyDuplicate(nums, k);
    return 0;
}