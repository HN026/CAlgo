#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spanningTree(int V, vector<vector<int>> &edges){
    int e = edges.size();
    vector<vector<pair<int,int>>> adj(V);
    for(int i = 0;  i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 0});
    // {wt, v}
    vector<int> vis(V);
    int sum = 0;

    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int weight = it.first;
        int node = it.second;

        if(vis[node]==1) continue;
        vis[node]=1;
        sum += weight;

        for(auto ad: adj[node]){
            int adjNode = ad.first;
            int wt = ad.second;

            if(!vis[adjNode]){
                q.push({wt, adjNode});
            }
        }
    }
    return sum;
}

int main(){

    int V = 5;
    // {u, v, weight}
	vector<vector<int>> edges =
     {{0, 1, 2},
      {0, 2, 1}, 
      {1, 2, 1}, 
      {2, 3, 2}, 
      {3, 4, 1}, 
      {4, 2, 2}};

	
	int sum = spanningTree(V, edges);
	cout << "The sum of all the edge weights: " << sum << endl;


    return 0;
}