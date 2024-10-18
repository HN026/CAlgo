#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxDistance(vector<vector<int>> &arrays) {
        int n = arrays.size();
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int maxDist = INT_MIN;

        for (int i = 1; i < n; i++) {
            maxDist = max(maxDist, abs(maxVal - arrays[i][0]));
            maxDist = max(maxDist, abs(arrays[i].back() - minVal));
            maxVal = max(maxVal, arrays[i].back());
            minVal = min(minVal, arrays[i][0]);
        }

        return maxDist;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arrays = {
        {1, 2, 3},
        {4, 5},
        {1, 2, 3}};

    int result = sol.maxDistance(arrays);
    cout << "The maximum distance is: " << result << endl;

    return 0;
}