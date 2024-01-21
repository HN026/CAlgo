#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// O(N+m)
// Topoligical Sorting using DFS Algo
void topologicalSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v]){
            topologicalSort(v, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n];
    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    vector<int> vis(n, 0);
    stack<int> st;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            topologicalSort(i, adj, vis, st);
        }
    }

    vector<int> dist(n, 1e9);
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;
            if(wt + dist[node] < dist[v]){
                dist[v] = wt + dist[node];
            }
        }
    }
    return dist;
}

int main() {
    int n = 6;
    int m = 7;
    vector<vector<int>> edges {
        {0,1,2},
        {0,4,1},
        {4,5,4},
        {4,2,2},
        {1,2,3},
        {2,3,6},
        {5,3,1}
    };

    vector<int> ans = shortestPathInDAG(n,m,edges);
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}