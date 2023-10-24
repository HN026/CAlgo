#include <bits/stdc++.h>
using namespace std;

vector<int> ShortestPath(vector<vector<int>> &edges, int N, int M, int src){
    vector<int> adj[N];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> distance(N, 1e9);
    distance[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(distance[node] + 1 < distance[it]){
                distance[it] = 1 + distance[node];
                q.push(it);
            }
        }
    }

    vector<int> ans(N, -1);
    for(int i = 0; i<N; i++){
        if(distance[i]!=1e9){
            ans[i] = distance[i];
        }
    }
    return ans;
}


int main(){
    int N = 9;
    int M = 10;

    vector<vector<int>> edges = {
        {0,1},
        {0,3},
        {3,4},
        {4,5},
        {5,6},
        {1,2},
        {2,6},
        {6,7},
        {7,8},
        {6,8}
    };

    vector<int> ans = ShortestPath(edges, N, M, 0);
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}