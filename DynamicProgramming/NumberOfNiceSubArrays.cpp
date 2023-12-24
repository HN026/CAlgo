#include <iostream>
#include <vector>

/*
*   dp[i] represents the number of subarrays with exactly i oddnumbers
*/

using namespace std;

int niceSubArrays(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    int count = 0;
    int odd = 0;

    for(int i = 0; i<n; i++){
        count += nums[i]%2;
        if(count>=k) odd += dp[count-k];
        dp[count]++;
    }
    return odd;
}





int main(){
    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    int ans = niceSubArrays(nums, k);
    cout<<ans<<endl;
    return 0;
}