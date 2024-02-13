#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool dfs(int node, int destination, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;

        for(auto adjNode: adj[node]){
            if(adjNode == destination) return true;
            if(!vis[adjNode] && dfs(adjNode, destination, adj, vis)) return true;
        }

        return false; 
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<vector<int>> adj(n);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        return dfs(source, destination, adj, vis);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int n = 3;
    int source = 0;
    int destination = 2;
    bool result = sol.validPath(n, edges, source, destination);
    cout << (result ? "True" : "False") << endl;
    return 0;
}