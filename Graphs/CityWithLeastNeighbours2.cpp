#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*Using Dijsktas Algorithm*/

vector<int> dijsktra(vector<vector<pair<int,int>>> adj, int src, int n){
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, src});

    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int weight = it.first;
        int node = it.second;

        for(auto ad: adj[node]){
            int adjNode = ad.first;
            int wt = ad.second;

            if(weight + wt < dist[adjNode]){
                dist[adjNode] = weight + wt;
                q.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int e = edges.size();
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<vector<int>> matrix;
    int ans = -1;
    for(int i = 0; i<n; i++){
        matrix.push_back(dijsktra(adj, i, n));
    }

    int overmin = INT_MAX;
    for(int i = 0; i<n; i++){
        int k = 0;
        for(int j = 0; j<n; j++){
            if(matrix[i][j]<=distanceThreshold){
                k++;
            }
        }
        if(k<=overmin){
            overmin = k;
            ans = i;
        }
    }

    return ans;
}

int main() {
    int n = 6;  // Number of nodes
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {2, 3, 1}, {1, 3, 10}, {1, 4, 2}, {3, 4, 10}, {3, 5, 1}};
    int distanceThreshold = 20;

    int result = findTheCity(n, edges, distanceThreshold);

    cout << result << endl;

    return 0;
}
