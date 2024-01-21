#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<int> slidingWindow(vector<int> &nums, int k){
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i<n; i++){
        if(!dq.empty() && dq.front()==i-k) dq.pop_front(); // We check here if we are if the front element in the deque is part of sliding window.

        while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back(); // We check for the back element 

        dq.push_back(i);
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}



int main(){
    vector<int> nums = {1,3,-1,-3,5,3, 6, 7};
    int k = 3;
    vector<int> ans = slidingWindow(nums, k);
    for(auto it: ans) cout<<it<<" ";

    return 0;
}