#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
public:

    int dfs(int s, vector<int> &dist, vector<vector<pair<int,int>>> &adj, vector<int> &dp){
        if(s==1) return 1;
        if(dp[s] != -1) return dp[s];
        int sum = 0;
        int weight = dist[s];
        for(auto &it: adj[s]){
            int distance = dist[it.first];
            if(distance > weight){
                sum = (sum%MOD + dfs(it.first, dist, adj, dp)%MOD)%MOD;
            }
        }

        return dp[s] = sum % MOD;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i<e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int source = n;
        vector<int> dist(n+1, INT_MAX);
        dist[source] = 0;
        pq.push({0, source});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int distance = it.first;
            int node = it.second;

            for(auto adjNode: adj[node]){
                int adNode = adjNode.first;
                int weight = adjNode.second;

                if(distance + weight < dist[adNode]){
                    dist[adNode] = distance + weight;
                    pq.push({dist[adNode], adNode});
                }
            }
        }

        vector<int> dp(n+1, -1);
        return dfs(n, dist, adj, dp);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2, 3}, {1, 3, 3}, {2, 3, 1}, {1, 4, 2}, {5, 2, 2}, {3, 5, 1}, {5, 4, 10}};
    int n = 5;
    int result = sol.countRestrictedPaths(n, edges);
    cout << "The number of restricted paths is: " << result << endl;
    return 0;
}