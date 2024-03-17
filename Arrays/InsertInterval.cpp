#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        vector<int> mergedInterval = {newInterval[0], newInterval[1]};
        while (i < n && intervals[i][0] <= newInterval[1]) {
            mergedInterval[0] = min(mergedInterval[0], intervals[i][0]);
            mergedInterval[1] = max(mergedInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(mergedInterval);

        while (i < n) {
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<int> newInterval = {0, 5};
    vector<vector<int>> result = solution.insert(intervals, newInterval);

    cout << "Merged intervals: " << endl;
    for (const auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}