#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool Dfs(int node, int parent, vector<int> adj[], int vis[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(Dfs(it, node, adj, vis)){
                return true;
            }
        }
        else if (it != parent){
            return true;
        }
    }
    return false;
}

bool detectCycle(vector<int> adj[]){
    int vis[5] = {0};
    for(int i = 0; i<5; i++){
        if(!vis[i]){
            if(Dfs(i, -1, adj, vis)){
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