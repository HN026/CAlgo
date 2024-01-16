/*
   Eventual safe states are those nodes in a directed graph
   where no matter what choices are made, you will eventually reach
   a terminal node (a node with no outgoing edges).
*/

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<int> &pathVis, vector<int> &vis, vector<int> &check) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: graph[node]) {
        if(!vis[it]) {
            if(dfs(it, graph, pathVis, vis, check)) return true;
        }
        else if(pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    check[node] = 1;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> pathVis(n, 0);
    vector<int> vis(n, 0);
    vector<int> check(n, 0);
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, graph, pathVis, vis, check);
        }
    }

    for(int i = 0; i < n; i++) {
        if(check[i]) ans.push_back(i);
    }
    return ans;
}

int main() {
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> result = eventualSafeNodes(graph);

    cout << "Eventual Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
