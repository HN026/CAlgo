#include<iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    for(int i = 0; i<n; i++) hash[i] = i;
    int maxi = 1;
    int lastIndex = 0; 

    sort(nums.begin(), nums.end());

    for(int index = 0; index<n; index++){
        for(int prev = 0; prev<index; prev++){
            if(nums[index]%nums[prev]==0 && dp[index]<1 + dp[prev]){
                dp[index] =  1 + dp[prev];
                hash[index] = prev;
            }
            if(dp[index]>maxi){
                maxi = dp[index];
                lastIndex = index;
            }
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }

    return temp;
}

int main(){
    vector<int> nums = {1,2, 4, 8};
    vector<int> temp = largestDivisibleSubset(nums);

    for(auto it: temp) cout<<it<<" ";
    cout<<endl;

    return 0;
}