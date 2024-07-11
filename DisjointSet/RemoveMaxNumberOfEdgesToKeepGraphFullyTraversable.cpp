#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  private:
    vector<int> sze;
    vector<int> parent;

  public:
    DisjointSet(int n) {
        sze.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ulparent_u = findUltimateParent(u);
        int ulparent_v = findUltimateParent(v);

        if (ulparent_u == ulparent_v)
            return;

        if (sze[ulparent_u] < sze[ulparent_v]) {
            parent[ulparent_u] = ulparent_v;
            sze[ulparent_v] += sze[ulparent_u];
        } else {
            parent[ulparent_v] = ulparent_u;
            sze[ulparent_u] += sze[ulparent_v];
        }
    }
};

class Solution {
  public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);
        int aliceEdges = 0;
        int bobEdges = 0;
        int edgesRemoved = 0;

        for (const auto &edge : edges) {
            if (edge[0] == 3) {
                bool addedAlice = false;
                bool addedBob = false;
                if (alice.findUltimateParent(edge[1]) != alice.findUltimateParent(edge[2])) {
                    alice.UnionBySize(edge[1], edge[2]);
                    addedAlice = true;
                }
                if (bob.findUltimateParent(edge[1]) != bob.findUltimateParent(edge[2])) {
                    bob.UnionBySize(edge[1], edge[2]);
                    addedBob = true;
                }
                if (addedAlice)
                    aliceEdges++;
                if (addedBob)
                    bobEdges++;
                if (!addedAlice && !addedBob)
                    edgesRemoved++;
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == 1) {
                if (alice.findUltimateParent(edges[i][1]) !=
                    alice.findUltimateParent(edges[i][2])) {
                    alice.UnionBySize(edges[i][1], edges[i][2]);
                    aliceEdges++;
                } else {
                    edgesRemoved++;
                }
            } else if (edges[i][0] == 2) {
                if (bob.findUltimateParent(edges[i][1]) !=
                    bob.findUltimateParent(edges[i][2])) {
                    bob.UnionBySize(edges[i][1], edges[i][2]);
                    bobEdges++;
                } else {
                    edgesRemoved++;
                }
            }
        }

        return (aliceEdges == n - 1 && bobEdges == n - 1) ? edgesRemoved : -1;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {1, 2, 3}, {2, 1, 4}, {2, 2, 3}};
    int n = 4;
    cout << sol.maxNumEdgesToRemove(n, edges) << endl;
    return 0;
}