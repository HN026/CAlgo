#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;

    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode, node, vis, adj)) return true;
        }
        else if(adjNode != parent) return true;
    }

    return false;
}


bool isCycle(vector<int> adj[], int V){
    vector<int> vis(V, 0);
    vis[0] = 1;

    for(int i = 0; i<V; i++){
        if(!vis[i]){
            if(dfs(i, -1, vis, adj)) return true;
        }
    }
    return false;
}


int main(){
    int V = 8;
    vector<int> adj[] = {{},{2,3},{1,5},{1,4,6},{3},{2,7},{3,7},{5,6}};
    bool ans = isCycle(adj, 8);
    cout<<ans<<endl;
    return 0;
}