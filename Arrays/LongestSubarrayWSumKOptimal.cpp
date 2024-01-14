#include <iostream>
#include <vector>

using namespace std;

// This method will only work if inside nums, there are only positive numbers.

int longestSubArray(vector<int> &nums, int k){
    int left = 0, right = 0, maxi = 0, sum=nums[0];
    int n = nums.size();
    while(right<n){
        while(left<=right && sum>k){
            sum -= nums[left];
            left++;
        }
        if(sum==k){
            maxi = max(maxi, right-left+1);
        }

        right++;
        if(right<n) sum += nums[right];
    }

    return maxi;
}

int main(){
    vector<int> nums = {2,3,5,1,9};
    int k = 10;

    int maxLen = longestSubArray(nums, k);
    cout<<maxLen<<endl;

    return 0;
}