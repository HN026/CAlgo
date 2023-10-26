#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void toposort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it.first]) toposort(it.first,adj,vis, st);
    }

    st.push(node);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int,int>> adj[n];
    for(auto it: edges) adj[it[0]].push_back({it[1], it[2]});

    stack<int> st;
    vector<int> vis(n,0);

    for(int i = 0; i<n; i++) if(!vis[i]) toposort(i,adj,vis,st);

    vector<int> distance(n, 1e9);
    distance[0] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: adj[node]){
            if(distance[node] + it.second < distance[it.first]) 
                distance[it.first] = distance[node] + it.second;
        }
    }

    for(int i = 0; i<n; i++)
        if(distance[i]==1e9) distance[i] = -1;

    return distance;
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