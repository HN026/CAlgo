#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits.h>

// Dijkstras Algorithms cannot be applied to graphs with negative weights as it will fall into infinite loop.
// Time complexity of Djikstras Algorithm is O(ElogV) where E is the number of edges and V is the number of vertices.

using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int v, int source){
    int e = edges.size();
    vector<vector<pair<int, int>>>adj(v);

    for(int i = 0; i<v; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);
    dist[source] = 0;
    st.insert({dist[source], source});

    while(!st.empty()){
        auto it = *(st.begin());
        int weight = it.first;
        int adjNode = it.second;
        st.erase(it);

        for(auto nd: adj[adjNode]){
            int node = nd.first;
            int wt = nd.second;

            if(weight + wt < dist[node]){
                if(dist[node]!=1e9){
                    st.erase({dist[node], node});
                }
                dist[node] = wt + weight;
                st.insert({dist[node], node});
            } 
        }
    }
    return dist;
}

int main(){

    int v = 4;
    vector<vector<int>> edges = {
        {0,1,5},
        {0,2,8},
        {1,2,9},
        {1,3,2},
        {2,3,6}
    };
    vector<int> ans = dijkstra(edges, v, 0);

    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}