#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({degree[i], i});
        }

        unordered_map<int, int> mp;
        int k = n;
        vector<int> vis(n, 0);
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (vis[it.second])
                continue;
            vis[it.second] = 1;
            mp[it.second] = k--;
            for (auto adjNode : adj[it.second]) {
                if (!vis[adjNode]) {
                    pq.push({degree[adjNode], adjNode});
                }
            }
        }

        long long int sum = 0;
        for (auto &it : roads) {
            sum += mp[it[0]] + mp[it[1]];
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}};
    int n = 10;
    long long result = sol.maximumImportance(n, roads);
    cout << "The maximum importance is: " << result << endl;
    return 0;
}