#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
        vis[node] = 1;
        for (auto adjNode : adj[node]) {
            if (vis[adjNode] == 1)
                return false;
            if (vis[adjNode] == 0) {
                if (!dfs(adjNode, vis, adj, st))
                    return false;
            }
        }
        vis[node] = 2;
        st.push(node);
        return true;
    }

    vector<int> topologicalSort(vector<vector<int>> &edges, int k) {
        vector<vector<int>> adj(k + 1);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(k + 1, 0);
        stack<int> st;
        for (int i = 1; i <= k; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, vis, adj, st))
                    return {};
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
        vector<int> rowOrder = topologicalSort(rowConditions, k);
        vector<int> colOrder = topologicalSort(colConditions, k);

        if (rowOrder.empty() || colOrder.empty())
            return {};
        vector<int> rowPosition(k + 1), colPosition(k + 1);
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int num = 1; num <= k; ++num) {
            ans[rowPosition[num]][colPosition[num]] = num;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int k = 3;
    vector<vector<int>> rowConditions = {{1, 2}, {2, 3}};
    vector<vector<int>> colConditions = {{2, 1}, {3, 2}};
    vector<vector<int>> result = solution.buildMatrix(k, rowConditions, colConditions);

    for (const auto &row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}