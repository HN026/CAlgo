#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Let's say we are xoring till ith element there the xor till ith element be xr
// Now let's assume till i - kth element the xor is x and from i-kth element to ith element the xor is k
// therefore we will say xr = x ^ k
// do xor k on bs
// x = xr ^ k
// Hence we will look for if x has occured before.

int NumberOfXors(vector<int> nums, int k){
    int n = nums.size();
    unordered_map<int,int> mp;
    mp[0] = 1;
    int cnt = 0;
    int preXor = 0;
    for(int right = 0; right<n; right++){
        preXor ^= nums[right];
        int x = preXor^k;
        cnt += mp[x];
        mp[preXor] += 1;
    }
    return cnt;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = NumberOfXors(nums, k);
    cout<<ans<<endl;
    return 0;
}