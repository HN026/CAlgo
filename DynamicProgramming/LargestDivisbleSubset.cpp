#include <bits/stdc++.h>

using namespace std;

void PrintLIS(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    for(int i = 0; i<n; i++) hash[i] = i;
    int maxi = 1;
    int lastIndex = 0;

    sort(nums.begin(), nums.end());
    
    for(int index = 0; index<n; index++){
        for(int prev = 0; prev<index; prev++){
            if(nums[index]%nums[prev]==0 && dp[index] < 1 + dp[prev]){
                dp[index] = 1 + dp[prev];
                hash[index] = prev;
            }
        }
        if(dp[index]>maxi){
            maxi = dp[index];
            lastIndex = index;
        }
    }

    vector<int> temp;

    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    for(auto it: temp) cout<<it<<" ";
    cout<<endl;
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    PrintLIS(nums);
    return 0;
}