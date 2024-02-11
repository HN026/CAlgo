#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        mp[nums[i]]++;
    }

    priority_queue<pair<int,int>> pq;
    for(auto it: mp){
        pq.push({it.second, it.first});
    }

    for(int i = 0; i<k; i++){
        if(!pq.empty()){
            auto k = pq.top();
            ans.push_back(k.second);
            pq.pop();
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    cout << "The top " << k << " frequent elements are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}