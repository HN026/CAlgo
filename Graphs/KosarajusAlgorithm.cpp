#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<vector<int>> &adjT, vector<int> &vis){
    vis[node] = 1;
    for(auto it: adjT[node]){
        if(!vis[it]){
            dfs3(it, adjT, vis);
        }
    }
}

int kosaraju(vector<vector<int>> &edges, int n){
    vector<vector<int>> adj(n);
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Step1 -> DFS to calculate Finishing times:
    stack<int> st;
    vector<int> vis(n, 0);
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    // Step2 -> Reversing the graph
    vector<vector<int>> adjT(n);
    for(int i = 0; i<n; i++){
        vis[i] = 0;
        for(auto it: adj[i]){
            // adj -> i -> it
            // adjT -> it -> i
            adjT[it].push_back(i);
        }
    }

    // Step3 -> DFS on reverse Graph using stack.
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs3(node, adjT, vis);
        }
    }

    return scc;
}

int main(){
    int n = 5;
    vector<vector<int>> edges {
        // {u, v}
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4},
    };

    int ans = kosaraju(edges, n);
    cout<<ans<<endl;

    return 0;
}