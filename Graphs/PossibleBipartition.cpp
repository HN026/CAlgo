#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool check(int node, int col, vector<vector<int>> &adj, vector<int> &color) {
        color[node] = col;

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (!check(it, !col, adj, color))
                    return false;
            } else if (color[it] == color[node])
                return false;
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!check(i, 0, adj, color))
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
    bool result = sol.possibleBipartition(n, dislikes);
    cout << (result ? "true" : "false") << endl;
    return 0;
}