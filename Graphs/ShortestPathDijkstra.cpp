#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int v, int source){
    vector<pair<int, int>> adj[v];
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> dist(v, 1e9);
    vector<int> parent(v);
    for(int i = 0; i<v; i++){
        parent[i] = i;
    }    
    dist[source] = 0;
    q.push({dist[source], source});
    
    while(!q.empty()){
      int distance = q.top().first;
      int parentNode = q.top().second;
      q.pop();

      for(auto node: adj[parentNode]){
        int adjNode = node.first;
        int wt = node.second;

        if(distance + wt < dist[adjNode]){
            dist[adjNode] = distance + wt;
            q.push({dist[adjNode], adjNode});
            parent[adjNode] = parentNode; 
        }
      }
    }

    if(dist[v-1]==1e9) return {-1};

    vector<int> ans;
    int node = v-1;
    while(parent[node] != node){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(source);

    reverse(ans.begin(), ans.end());
    return ans;
}



int main(){
    vector<vector<int>> edges = {
    {0,1,5},
    {0,2,8},
    {1,2,9},
    {1,3,2},
    {2,3,6}
};
    int v = edges.size();
    vector<int> ans = dijkstra(edges, 4, 0);

    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}