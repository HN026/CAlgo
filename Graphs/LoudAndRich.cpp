#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis,
             vector<int> &ans, vector<int> &quiet) {
        vis[node] = 1;

        for (auto &adjNode : adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis, ans, quiet);
            }
            if (quiet[ans[node]] > quiet[ans[adjNode]]) {
                ans[node] = ans[adjNode];
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {

        int e = richer.size();
        int n = quiet.size();
        vector<int> ans(n);
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

        for (int i = 0; i < e; i++) {
            int v = richer[i][0];
            int u = richer[i][1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, ans, quiet);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};
    vector<int> result = sol.loudAndRich(richer, quiet);
    for (const auto &num : result) {
        cout << num << " ";
    }
    return 0;
}