/*
   Eventual safe states are those nodes in a directed graph
   where no matter what choices are made, you will eventually reach
   a terminal node (a node with no outgoing edges).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> RevGraph(n);
    vector<int> inDegree(n, 0);

    for(int i = 0; i<n; i++){
        // i -> it
        for(auto it: graph[i]){
            RevGraph[it].push_back(i); // it-> i
            inDegree[i]++;
        }
    }
    
    queue<int> q;
    vector<int> safeNodes;
    for(int i = 0; i<n; i++){
        if(!inDegree[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for(auto it: RevGraph[node]){
            inDegree[it] -=1;
            if(!inDegree[it]){
                q.push(it);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main() {
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> result = eventualSafeNodes(graph);

    cout << "Eventual Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
