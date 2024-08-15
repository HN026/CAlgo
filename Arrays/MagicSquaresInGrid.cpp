#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isMagicSquare(int i, int j, int n, int m, vector<vector<int>> &grid) {
        if (i + 2 >= n || j + 2 >= m)
            return false;

        int r1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int r2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        int r3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

        int c1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        int c2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        int c3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

        int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int d2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

        if (r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == d1 && d1 == d2) {
            vector<int> freq(10, 0);
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    int val = grid[i + a][j + b];
                    if (val < 1 || val > 9 || freq[val] > 0)
                        return false;
                    freq[val]++;
                }
            }
            return true;
        }

        return false;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for (int row = 0; row < n - 2; row++) {
            for (int col = 0; col < m - 2; col++) {
                if (isMagicSquare(row, col, n, m, grid))
                    count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}};

    int result = sol.numMagicSquaresInside(grid);
    cout << "Number of magic squares: " << result << endl;

    return 0;
}