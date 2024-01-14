#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// Can work for both positive as well as negative numbers.

int longestSubArray(vector<int> &nums, int k){
    int n = nums.size();
    unordered_map<int, int> preSum;
    
    int sum = 0;
    int maxLen = 0;
    for(int i = 0; i<n; i++){
        sum += nums[i];

        if(sum==k){
            maxLen = max(maxLen, i+1);
        }

        int rem = sum - k;

        if(preSum.find(rem)!=preSum.end()){
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }

        if(preSum.find(sum)==preSum.end()){
            preSum[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    vector<int> nums = {-1,2,3,5,1,9};
    int k = 9;

    int maxLen = longestSubArray(nums, k);
    cout<<maxLen<<endl;

    return 0;
}