#include <iostream>
#include <vector>

using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj,
         vector<int> &timein, vector<int> &timelow,
         vector<vector<int>> &bridges) {
  vis[node] = 1;
  timein[node] = timelow[node] = timer;
  timer++;

  for (auto it : adj[node]) {
    if (it == parent)
      continue;
    if (vis[it] == 0) {
      dfs(it, node, vis, adj, timein, timelow, bridges);
      timelow[node] = min(timelow[it], timelow[node]);

      if (timelow[it] > timein[node]) {
        bridges.push_back({it, node});
      }
    } else {
      timelow[node] = min(timelow[node], timelow[it]);
    }
  }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
  vector<vector<int>> adj(n);
  for (auto it : connections) {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> vis(n, 0);
  vector<int> timein(n);
  vector<int> timelow(n);
  vector<vector<int>> bridges;
  dfs(0, -1, vis, adj, timein, timelow, bridges);
  return bridges;
}

int main() {
  vector<vector<int>> connections = {
      {0, 1},
      {1, 2},
      {2, 0},
      {1, 3},
  };
  int n = 4;

  vector<vector<int>> bridges = criticalConnections(n, connections);

  for (auto it : bridges) {
    cout << it[0] << " " << it[1] << endl;
  }

  return 0;
}