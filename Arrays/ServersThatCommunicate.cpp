#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int countServers(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (rows[i] >= 2 || cols[j] >= 2))
                    total++;
            }
        }

        return total;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 0, 0, 1}};

    Solution solution;
    int result = solution.countServers(grid);
    cout << result << endl;

    return 0;
}