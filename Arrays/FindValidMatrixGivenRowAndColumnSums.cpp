#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum,
                                      vector<int> &colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = 0;
                if (rowSum[i] >= colSum[j])
                    x = colSum[j];
                else
                    x = rowSum[i];
                rowSum[i] -= x;
                colSum[j] -= x;
                ans[i][j] = x;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> rowSum = {3, 8};
    vector<int> colSum = {4, 7};

    Solution s;

    vector<vector<int>> ans = s.restoreMatrix(rowSum, colSum);
    for (auto &it : ans) {
        for (auto &it2 : it)
            cout << it2 << " ";
        cout << endl;
    }

    return 0;
}