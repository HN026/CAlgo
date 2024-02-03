#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxFrequency(vector<int> &nums, int k){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    int maximam = 1;
    int left = 0;
    int right = 0;

    while(true){
        while(right+1<n && nums[left]-nums[right+1]<=k){
            k -= nums[left] - nums[right+1];
            right++;
        }
        int length = right - left + 1;
        maximam = max(maximam, length);

        if(right == n-1) break;
        int diff = nums[left] - nums[left+1];
        k +=  (length-1)*diff;
        left++;
    }
    return maximam;
}


int main(){
    vector<int> nums = {2, 7, 9, 10, 6, 13};
    int k = 8;
    int ans = maxFrequency(nums, k);
    cout<<ans<<endl;
    return 0;
}

