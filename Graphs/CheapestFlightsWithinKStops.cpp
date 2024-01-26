#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    int e = flights.size();
    for(int i = 0; i < e; i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];
        adj[u].push_back({v, wt});
    }

    /*{stops, {node, distancec}}*/
    queue<pair<int, pair<int,int>>> q;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    q.push({0, {src, 0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int weight = it.second.second;

        if(stops > k) continue;
        for(auto ad: adj[node]){
            int adjNode = ad.first;
            int wt = ad.second;
            if(wt + weight < dist[adjNode] && stops <= k){
                dist[adjNode] = wt + weight;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }   
    }

    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}

int main() {
    int n = 5;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 200}, {0, 2, 500}, {2, 3, 250}, {1, 3, 300}};
    int src = 0;
    int dst = 3;
    int k = 1;

    int result = findCheapestPrice(n, flights, src, dst, k);

    if (result == -1) {
        cout << "No valid route found within the given constraints." << endl;
    } else {
        cout << "Cheapest price from node " << src << " to node " << dst << " with at most " << k << " stops: " << result << endl;
    }

    return 0;
}
