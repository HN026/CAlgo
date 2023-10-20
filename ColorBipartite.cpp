#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int V, vector<int> adj[]){
    queue<int> q;
    q.push(0);
    vector<int> color(V, -1);
    color[0] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it]==color[node]){
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
