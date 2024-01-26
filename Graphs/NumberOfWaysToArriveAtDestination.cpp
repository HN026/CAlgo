#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int mod = 1000000007;

int countPaths(int n, vector<vector<int>>& roads) {
    long long e = roads.size();
    vector<vector<pair<long long, long long>>> adj(n);
    for (int i = 0; i < e; i++) {
        long long u = roads[i][0];
        long long v = roads[i][1];
        long long wt = roads[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    vector<long long> dist(n, LLONG_MAX);
    vector<long long> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        long long weight = it.first;
        long long node = it.second;

        for (auto ad : adj[node]) {
            long adjNode = ad.first;
            long adjWeight = ad.second;

            if (adjWeight + weight < dist[adjNode]) {
                dist[adjNode] = adjWeight + weight;
                q.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node] % mod;
            } else if (adjWeight + weight == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}

int main() {
    int n = 5;
    vector<vector<int>> roads = {{0, 1, 2}, {0, 2, 3}, {1, 3, 1}, {2, 3, 3}, {2, 4, 2}, {3, 4, 1}};

    int result = countPaths(n, roads);
    cout << "Number of shortest paths: " << result << endl;

    return 0;
}
