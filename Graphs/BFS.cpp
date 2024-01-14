#include <bits/stdc++.h>

using namespace std;

vector<int> BFS(vector<int> adj[], int V){
    vector<int> vis(V, 0);
    vis[0] = 1;
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    vector<int> adj[6];
    int V = 6;

    adj[0] = {0};
    adj[1] = {2,5};
    adj[2] = {1,5,3};
    adj[3] = {2,4,5};
    adj[4] = {3,5};
    adj[5] = {1,2,3,4};

    vector<int> ans = BFS(adj, V);
    for(auto it: ans) cout<<it<<" ";

    return 0;
}