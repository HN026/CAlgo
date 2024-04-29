#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (land[row][col] && !vis[row][col]) {
                    int nrow = row;
                    int ncol = col;
                    for (nrow = row; nrow < n && land[nrow][col]; nrow++) {
                        for (ncol = col; ncol < m && land[nrow][ncol]; ncol++) {
                            if (vis[nrow][ncol] == 0) {
                                vis[nrow][ncol] = 1;
                            }
                        }
                    }

                    ans.push_back({row, col, nrow - 1, ncol - 1});
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    vector<vector<int>> result = sol.findFarmland(land);
    for (auto &group : result) {
        cout << "[" << group[0] << ", " << group[1] << ", " << group[2] << ", " << group[3] << "]" << endl;
    }
    return 0;
}