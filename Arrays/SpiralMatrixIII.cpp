#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool inside(int i, int j, int rows, int cols) {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;
        vector<vector<int>> ans(total);
        ans[0] = {rStart, cStart};
        int layer = max({rows - rStart, cols - cStart, rStart + 1, cStart + 1}) + 1;
        int i = rStart, j = cStart, k = 1;

        for (int m = 1; m < layer; m++) {
            int di = 0, dj = 1, step = 2 * m - 1;
            for (int a = 0; a < step; a++) {
                i += di, j += dj;
                if (inside(i, j, rows, cols))
                    ans[k++] = {i, j};
            }
            di = 1, dj = 0;
            for (int a = 0; a < step; a++) {
                i += di, j += dj;
                if (inside(i, j, rows, cols))
                    ans[k++] = {i, j};
            }
            di = 0, dj = -1;
            step++;
            for (int a = 0; a < step; a++) {
                i += di, j += dj;
                if (inside(i, j, rows, cols))
                    ans[k++] = {i, j};
            }
            di = -1, dj = 0;
            for (int a = 0; a < step; a++) {
                i += di, j += dj;
                if (inside(i, j, rows, cols))
                    ans[k++] = {i, j};
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int rows = 5, cols = 6, rStart = 1, cStart = 4;
    vector<vector<int>> result = sol.spiralMatrixIII(rows, cols, rStart, cStart);

    for (const auto &pos : result) {
        cout << "[" << pos[0] << ", " << pos[1] << "] ";
    }
    cout << endl;

    return 0;
}