#include <iostream>
#include <vector>
using namespace std;

void dfs(int index, vector<int> &temp, vector<int> &vis,
         vector<vector<int>> &graph, vector<vector<int>> &ans, int n) {
  if (index == n - 1) {
    ans.push_back(temp);
    return;
  }

  for (auto node : graph[index]) {
    if (!vis[node]) {
      vis[node] = 1;
      temp.push_back(node);
      dfs(node, temp, vis, graph, ans, n);
      vis[node] = 0;
      temp.pop_back();
    }
  }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> vis(n + 1, 0);
  vector<int> temp;
  temp.push_back(0);
  vector<vector<int>> ans;
  dfs(0, temp, vis, graph, ans, n);

  return ans;
}

int main() {
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

  vector<vector<int>> result = allPathsSourceTarget(graph);

  cout << "All paths from source to target are:" << endl;
  for (const auto &path : result) {
    for (int node : path) {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}