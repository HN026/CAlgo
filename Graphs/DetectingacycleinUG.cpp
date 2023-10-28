#include <iostream>
#include <vector>
#include <queue>

// Using BFS

using namespace std;

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if (parent != adjNode){
                return true;
            }
        }
    }
    return false;
}


bool detectCycle(vector<int> adj[]){
    int vis[5] = {0};
    for(int i = 0; i<5; i++){
        if(!vis[i]){
            if(detect(i, adj, vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> adj[] = {{4,4}, {0,1}, {1,2}, {2,3}, {3,0}};
    bool ans = detectCycle(adj);
    cout<<ans<<endl;
    return 0;
}