#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        for (auto &adjNode : adj[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = true;
                dfs(adjNode, adj, vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n);
            dfs(i, adj, visited);
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (visited[i])
                    temp.push_back(i);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    vector<vector<int>> ancestors = sol.getAncestors(4, edges);
    for (auto &nodes : ancestors) {
        for (auto &node : nodes) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}