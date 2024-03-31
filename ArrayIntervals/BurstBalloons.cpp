#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end());
        int n = points.size();

        vector<vector<int>> ans;
        for (auto &point : points) {
            if (ans.size() == 0 || ans.back()[1] < point[0]) {
                ans.push_back(point);
            } else if (ans.back() == point)
                continue;
            else {
                auto temp = ans.back();
                ans.pop_back();
                ans.push_back({max(temp[0], point[0]), min(temp[1], point[1])});
            }
        }

        return ans.size();
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int result = solution.findMinArrowShots(points);

    cout << "Minimum number of arrows required: " << result << endl;

    return 0;
}