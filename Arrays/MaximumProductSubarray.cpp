#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxProductSubarray(vector<int> &nums){
    int pre = 1;
    int suff = 1;
    int n = nums.size();
    int ans = INT_MIN;
    for(int i = 0; i<n; i++){
        if(pre==0) pre = 1;
        if(suff==0) suff = 1;

        pre = pre * nums[i];
        suff = suff * nums[n-1-i];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}


int main(){
    vector<int> nums = {-5, -4, 2, 3, 0, -7, 8};
    int ans = maxProductSubarray(nums);
    cout<<ans<<endl;
    return 0;
}