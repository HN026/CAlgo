#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isPossible(const vector<int> &a, const vector<int> &b) {
        long long int x = abs(a[0] - b[0]);
        long long int y = abs(a[1] - b[1]);
        long long int z = (long long)a[2] * a[2];
        return x * x + y * y <= z;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &c) {
        vis[node] = 1;
        c = c + 1;
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis, c);
            }
        }
    }

    int maximumDetonation(vector<vector<int>> &bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (isPossible(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
            }
        }

        int maxi = 1;
        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            int c = 0;
            dfs(i, adj, vis, c);
            maxi = max(maxi, c);
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> bombs = {{0, 0, 1}, {0, 2, 1}, {2, 0, 1}, {2, 2, 1}};
    cout << sol.maximumDetonation(bombs) << endl;
    return 0;
}