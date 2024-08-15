#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        vector<int> mappedOrder(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            string numStr = to_string(nums[i]);
            for (char &c : numStr) {
                c = '0' + mapping[c - '0'];
            }
            mappedOrder[i] = stoi(numStr);
        }

        vector<int> indices(nums.size());
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return mappedOrder[a] == mappedOrder[b] ? a < b : mappedOrder[a] < mappedOrder[b];
        });

        vector<int> sortedNums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sortedNums[i] = nums[indices[i]];
        }

        return sortedNums;
    }
};

int main() {
    Solution solution;
    vector<int> mapping = {2, 1, 4, 8, 6, 3, 0, 9, 7, 5};
    vector<int> nums = {991, 338, 38};
    vector<int> sortedNums = solution.sortJumbled(mapping, nums);

    for (int num : sortedNums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}