#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            dfs(adjNode, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> TopologicalSort(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    stack<int> st;

    for(int i = 0; i<V; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    int V = 6;
    vector<vector<int>> adj[V] = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2},
    };

    vector<int> ans = TopologicalSort(V, adj);
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;


    return 0;
}