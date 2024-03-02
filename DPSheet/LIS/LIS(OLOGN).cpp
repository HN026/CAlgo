#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getBestCandidate(map<int, int> &candidates, int num) {
    auto it = candidates.lower_bound(num);
    if(it == candidates.begin()) return 0;
    it--;
    return it->second;
}

void insert(map<int,int> &candidates, int num, int adv){
    auto it = candidates.lower_bound(num);
    if(it != candidates.end() && it->first==num) return;
    it = candidates.insert(it, {num, adv});
    it++;
    while(it!=candidates.end() && it->second <= adv){
        auto temp = it;
        it++;
        candidates.erase(temp);
    } 
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        map<int, int> candidates;

        dp[0] = 1;
        candidates[nums[0]] = dp[0];

        for(int i = 1; i<n; i++){
            dp[i] = 1 + getBestCandidate(candidates, nums[i]);
            insert(candidates, nums[i], dp[i]);
        }
    
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence is: " << length << endl;
    return 0;
}