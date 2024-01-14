#include <iostream>
#include <vector>

using namespace std;

void DFSUtil(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs){
    vis[node] = 1;
    dfs.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            DFSUtil(it, adj, vis, dfs);
        }
    }
}

vector<int> DFS(vector<int> adj[], int V){
    vector<int> vis(V, 0);
    vis[0] = 1;
    vector<int> dfs;
    DFSUtil(1, adj, vis, dfs);
    return dfs;
}

int main(){
    vector<int> adj[9];
    adj[0] = {};
    adj[1] = {2,3};
    adj[2] = {1,5,6};
    adj[3] = {1,4,7};
    adj[4] = {3,8};
    adj[5] = {2};
    adj[6] = {2};
    adj[7] = {3,8};
    adj[8] = {4,7};

    int V = 9;

    vector<int> ans = DFS(adj, V);
    for(auto it: ans) cout<<it<<" ";

    return 0;
}