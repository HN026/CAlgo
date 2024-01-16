#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Kahn Algorithm is basically TopoSort using BFS.

vector<int> TopologicalSort(int V, vector<int> adj[]){
    vector<int> inDegree(V, 0);
    for(int i = 0; i<V; i++){
        for(auto it: adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0; i<V; i++){
        if(!inDegree[i]){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        topo.push_back(current);
        for(auto node: adj[current]){
            inDegree[node]--;
            if(!inDegree[node]){
                q.push(node);
            }
        }
    }

    return topo;
}


int main(){
    int V = 6;
    vector<int> adj[V] = {
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