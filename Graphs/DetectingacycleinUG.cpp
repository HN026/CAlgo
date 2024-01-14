#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool BFS(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});
    while(!q.empty()){
        int currentNode = q.front().first;
        int parent = q.front().second;

        for(auto adjNode: adj[currentNode]){
            if(!vis[adjNode]){
                q.push({adjNode, currentNode});
                vis[adjNode] = 1;
            }
            else if(adjNode != parent){
                return true; // Yes it's a cycle
            }
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int V){
    vector<int> vis(V, 0);
    vis[0] = 1;
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            if(BFS(i, adj, vis)) return true;
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