#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
  vector<int> size;
  vector<int> parent;

public:
  DisjointSet(int n) {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int findUltimateParent(int node) {
    if (parent[node] == node) {
      return node;
    }
    return parent[node] = findUltimateParent(parent[node]);
  }

  void UnionBySize(int u, int v) {
    int ulparent_u = findUltimateParent(u);
    int ulparent_v = findUltimateParent(v);

    if (ulparent_u == ulparent_v)
      return;

    if (size[ulparent_u] < size[ulparent_v]) {
      parent[ulparent_u] = ulparent_v;
      size[ulparent_v] += size[ulparent_u];
    } else {
      parent[ulparent_v] = ulparent_u;
      size[ulparent_u] += size[ulparent_v];
    }
  }
};

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
  vector<int> ans;
  int n = edges.size();
  DisjointSet ds(n);

  for (int i = 0; i < n; i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    if (ds.findUltimateParent(u) == ds.findUltimateParent(v)) {
      ans.push_back(u);
      ans.push_back(v);
      continue;
    }
    ds.UnionBySize(u, v);
  }

  return ans;
}

int main() {
    // Example usage
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    
    vector<int> redundantConnection = findRedundantConnection(edges);

    if (redundantConnection.empty()) {
        cout << "No redundant connection found." << endl;
    } else {
        cout << "Redundant connection found: " << redundantConnection[0] << " - " << redundantConnection[1] << endl;
    }

    return 0;
}