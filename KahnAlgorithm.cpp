#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<int> adj[], int V) {
    int indegree[6] = {0};

    for (int i = 0; i < V; i++) {
        for (auto it: adj[i]) indegree[it]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if(!indegree[i]) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (!indegree[it]) q.push(it);
        }
    }
    return topo;
}

int main() {
    int V = 6;
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

    vector<int> ans = topologicalSort(adj, 6);

    for (auto it : ans) {
        cout << it << " ";
    }

    cout << endl;
    return 0;
}
