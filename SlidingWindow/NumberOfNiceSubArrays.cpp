#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] % 2) nums[i] = 1;
        else nums[i] = 0;
    }

    int preSum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        preSum += nums[i];
        int remove = preSum - k;
        cnt += mp[remove];
        mp[preSum] += 1;
    }

    return cnt;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = numberOfSubarrays(nums, k);

    cout << "Number of subarrays with " << k << " odd elements: " << result << endl;

    return 0;
}
