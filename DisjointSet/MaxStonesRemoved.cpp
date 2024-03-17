#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> size;

  public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return parent[node];
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ulparent_u = findUltimateParent(u);
        int ulparent_v = findUltimateParent(v);

        if (ulparent_u == ulparent_v)
            return;

        if (size[ulparent_u] < size[ulparent_v]) {
            parent[ulparent_u] = ulparent_v;
            size[ulparent_v] += size[ulparent_u];
        } else {
            parent[ulparent_v] = ulparent_u;
            size[ulparent_u] += size[ulparent_v];
        }
    }
};

class Solution {
  public:
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for (auto &it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;

        for (auto &it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.UnionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUltimateParent(it.first) == it.first)
                cnt++;
        }

        return n - cnt;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    int result = solution.removeStones(stones);
    cout << "Maximum number of stones that can be removed: " << result << endl;
    return 0;
}