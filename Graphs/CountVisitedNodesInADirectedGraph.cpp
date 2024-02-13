#include <iostream>
#include <vector>

using namespace std;

const int PRV_DFS = 1;
const int CUR_DFS = 2;

void dfs(int source, vector<int> &visited, vector<int> &result,
         vector<int> &edges) {

  if (result[source] != -1)
    return;
  if (visited[source] == CUR_DFS) {
    int len = 1;
    int cur = source;
    while (edges[cur] != source) {
      len++;
      cur = edges[cur];
    }

    cur = source;
    while (edges[cur] != source) {
      result[cur] = len;
      cur = edges[cur];
    }
    result[cur] = len;
    return;
  }

  visited[source] = CUR_DFS;
  dfs(edges[source], visited, result, edges);
  if (result[source] == -1) {
    result[source] = result[edges[source]] + 1;
  }

  visited[source] = PRV_DFS;
}

vector<int> countVistedNodes(vector<int> &edges) {
  int n = edges.size();
  vector<int> visited(n, 0);
  vector<int> result(n, -1);

  for (int i = 0; i < n; i++)
    dfs(i, visited, result, edges);

  return result;
}

int main() {

  vector<int> edges = {1, 2, 0, 0};

  vector<int> res = countVistedNodes(edges);
  for (auto it : res) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}