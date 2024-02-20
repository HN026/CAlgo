#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto &it : count) {
            heap.push(it.second);
        }

        while (k > 0) {
            k -= heap.top();
            heap.pop();
        }

        if (k < 0) {
            return heap.size() + 1;
        }

        return heap.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 1, 1, 3, 3, 2};
    int k = 3;
    int result = sol.findLeastNumOfUniqueInts(nums, k);
    cout << "The least number of unique integers after removing " << k << " elements is: " << result << endl;
    return 0;
}