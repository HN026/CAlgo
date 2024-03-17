#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto &interval : intervals) {
            if (ans.size() == 0 || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                auto temp = ans.back();
                ans.pop_back();
                ans.push_back({temp[0], max(temp[1], interval[1])});
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = solution.merge(intervals);

    cout << "Merged intervals: " << endl;
    for (const auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}