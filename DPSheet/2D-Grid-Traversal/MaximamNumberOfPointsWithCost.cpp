#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    long long maxPoints(vector<vector<int>> &points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> prev(m, 0);
        for (int j = 0; j < m; j++)
            prev[j] = points[0][j];

        for (int i = 1; i < n; i++) {
            vector<long long> curr(m, 0), left(m, 0), right(m, 0);

            left[0] = prev[0];
            for (int j = 1; j < m; j++)
                left[j] = max(left[j - 1] - 1, prev[j]);

            right[m - 1] = prev[m - 1];
            for (int j = m - 2; j >= 0; j--)
                right[j] = max(right[j + 1] - 1, prev[j]);

            for (int j = 0; j < m; j++)
                curr[j] = points[i][j] + max(left[j], right[j]);

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};

int main() {
    vector<vector<int>> points = {
        {1, 2, 3},
        {1, 5, 1},
        {3, 1, 1}};
    Solution sol = Solution();
    cout << sol.maxPoints(points) << endl;
    return 0;
}