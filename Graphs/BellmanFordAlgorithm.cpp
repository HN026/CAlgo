#include <iostream>
#include <vector>

using namespace std;

// O(V*E) -> TC

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src){
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    for(int i = 0; i<V-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e9 && dist[u] + wt < dist[v]){
                dist[v] = wt + dist[u];
            }
        }
    }

    // If more relaxations occur at Nth iterations means there is a negative weight cycle otherwise we would get the shortest distance to all the nodes from the source in the N-1th iteration at worse itself.
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u]!=1e9 && dist[u]+wt<dist[v]){
            return {-1};
        }
    }

    return dist;
}

int main(){
    int V = 6;
    vector<vector<int>> edges = {
        {3,2,6},
        {5,3,1},
        {0,1,5},
        {1,5,-3},
        {1,2,-2},
        {3,4,-2},
        {2,4,3}
    };

    vector<int>ans = bellmanFord(V, edges, 0);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}