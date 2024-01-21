#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// We will be doing it using bfs.
vector<int> ShortestPath(vector<vector<int>> &edges, int N, int M, int src){
    vector<int> adj[N];
    for(int i = 0; i<M; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    queue<int> q;
    vector<int> dist(N, 1e9);
    dist[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    vector<int> ans;
    for(auto it: dist){
        if(it==1e9) ans.push_back(-1);
        else ans.push_back(it);
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