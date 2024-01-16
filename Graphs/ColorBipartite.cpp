#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// If a graph has odd length cycle, it can't be bipartite colored graph.

// A bipartite graph is a graph whose vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent.

bool check(int start, vector<int> adj[], vector<int> &color){
    color[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adj: adj[node]){
            if(color[adj]==-1){
                color[adj] = !color[node];
                q.push(adj);
            }
            else if(color[adj] == color[node]){
                return false;
            }
        }
    }
    return true;
}


bool isBipartite(int V, vector<int> adj[]){
    vector<int> color(V, -1);

    for(int i = 0; i<V; i++){
        if(color[i]==-1){
            if(!check(i, adj, color)){
                return false;
            }
        }
    }
    return true;
}


int main() {
    int V = 4; 
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    if (isBipartite(V, adj)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
