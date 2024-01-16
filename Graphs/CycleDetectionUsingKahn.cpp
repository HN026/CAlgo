#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Directed Graph

bool isCycle(int V, vector<int> adj[]){
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
    int cnt = 0;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        cnt++;
        for(auto node: adj[current]){
            inDegree[node]--;
            if(!inDegree[node]){
                q.push(node);
            }
        }
    }

    return !(cnt==V);
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

    bool ans = isCycle(V, adj);
    cout<<ans<<endl;

    return 0;
}