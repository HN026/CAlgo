#include <iostream>
#include <vector>
#include <queue>

using namespace std;


double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node){
    int e = edges.size();
    vector<vector<pair<int, double>>>adj(n);
    
    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        double probwt = succProb[i];
        adj[u].push_back({v, probwt});
    }

    // priority_queue<pair<double,int>> q; // You can generate a priority queue that's a max heap like this as well but I will be using Lambda expression

    auto comp = [](pair<double, int> &a, pair<double, int> &b){
        return a.first<b.first;
    };

    priority_queue<pair<double,int>, vector<pair<double,int>>, decltype(comp)> q(comp);

    vector<double> prob(n, 0);
    prob[start_node] = 1;
    q.push({prob[start_node], start_node });

    while(!q.empty()){
        double probwt = q.top().first;
        int adjNode = q.top().second;
        q.pop();

        for(auto it: adj[adjNode]){
            int node = it.first;
            double proba = it.second;
            if(proba * probwt > prob[node]){
                prob[node] = proba * probwt;
                q.push({prob[node], node});
            }
        }
    }
    return prob[end_node];
}

int main() {
    int n = 3; // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start_node = 0;
    int end_node = 2;

    double result = maxProbability(n, edges, succProb, start_node, end_node);

    cout << "The maximum probability of reaching node " << end_node << " from node " << start_node << " is: " << result << endl;

    return 0;
}
