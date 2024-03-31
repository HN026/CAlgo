#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> id;
    vector<bool> visited;
    int ans;

  public:
    void personToSeat(vector<int> &row) {
        int n = row.size();
        id.resize(n);
        for (int i = 0; i < n; i++) {
            id[row[i]] = i;
        }
    }

    int findPartner(int x) {
        return (x & 1) == 1 ? x - 1 : x + 1;
    }

    int dfs(vector<int> &row, int idx, int partner) {
        if (row[idx] == partner)
            return 0;

        int currPartner = findPartner(row[idx]);
        int currPartnerIdx = id[currPartner];
        int currPartnerNext = currPartnerIdx ^ 1;

        visited[row[idx]] = true;
        visited[currPartner] = true;

        return 1 + dfs(row, currPartnerNext, partner);
    }

    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        visited.resize(n, false);
        ans = 0;

        personToSeat(row);

        for (int i = 0; i < n; i += 2) {
            if (!visited[row[i]]) {
                visited[row[i]] = true;
                visited[findPartner(row[i])] = true;
                int partner = findPartner(row[i]);
                int swaps = dfs(row, i + 1, partner);
                ans += swaps;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> row = {0, 2, 1, 3};
    int result = solution.minSwapsCouples(row);
    cout << "Minimum number of swaps required: " << result << endl;
    return 0;
}