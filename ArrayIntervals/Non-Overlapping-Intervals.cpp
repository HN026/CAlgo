#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (ans.size() == 0 || ans.back()[1] <= intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                auto temp = ans.back();
                ans.pop_back();
                if (temp[1] <= intervals[i][1]) {
                    ans.push_back(temp);
                } else {
                    ans.push_back(intervals[i]);
                }
            }
        }

        return n - ans.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}