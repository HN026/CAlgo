#include <bits/stdc++.h>

using namespace std;

int minimumMountainRemovals(vector<int> &nums) {
    int n = nums.size();

    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);

    for(int index = 0; index<n; index++){
        for(int prev = 0; prev<index; prev++){
            if(nums[prev]<nums[index]){
                dp1[index] = max(dp1[index], 1 + dp1[prev]);
            }
        }
    }

    for(int index = n-1; index>=0; index--){
        for(int prev = n-1; prev>index; prev--){
            if(nums[prev]<nums[index]){
                dp2[index] = max(dp2[index], 1 + dp2[prev]);
            }
        }
    }

    int maxi = 0;
    for(int i = 0; i<n; i++){
        if(dp1[i]>1 && dp2[i]>1){
            maxi = max(maxi, dp1[i] + dp2[i] -1);
        }
    }

    return n-maxi;
}



int main(){
    vector<int> nums = {2,1,1,5,6,2,3,1};
    int n = nums.size();

    int ans = minimumMountainRemovals(nums);
    cout<<ans<<endl;

    return 0;
}