#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int col, int Color[], vector<int> adj[]){
    Color[node] = col;

    for (auto it: adj[node]){
        if(Color[it]==-1){
            if(dfs(it, !col, Color,adj)==false){
                return false;
            }
            else if (Color[it]==col){
                return false;
            }
        }
    }
    return true;
}


bool isBipartite(int V, vector<int> adj[]){
    int Color[4];
    for(int i = 0; i<V; i++){
        Color[i] = -1;
    }

    for(int i = 0; i<4; i++){
        if(Color[i]==-1){
            if(dfs(i,0,Color,adj)==false){
                return false;
            }
        }
    }
    return true;
}





int main() {
    int V = 4; 
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    if (isBipartite(V, adj)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
