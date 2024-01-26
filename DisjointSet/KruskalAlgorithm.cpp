#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Graph is undirected.

class DisjointSet{
    private:
        vector<int> size;
        vector<int> parent;
    public:
        DisjointSet(int n){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++) parent[i] = i;
        }

        int findUltimateParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void UnionBySize(int u, int v){
            int ulparent_u = findUltimateParent(u);
            int ulparent_v = findUltimateParent(v);

            if(ulparent_u==ulparent_v) return;

            if(size[ulparent_u]<size[ulparent_v]){
                parent[ulparent_u] = ulparent_v;
                size[ulparent_v] += ulparent_u;
            }
            else{
                parent[ulparent_v] = ulparent_u;
                size[ulparent_u] += ulparent_v;
            }
        }
};

int spanningTree(int V, vector<vector<int>> &edges){
    // In this I'm adding edges in a Unidirectional manner but even if there are bidirectional edges, they will get rejected anyone after one is added because of the ultimate parent being same.
    vector<pair<int, pair<int,int>>> adj(V);
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj.push_back({wt, {u, v}});
    }

    int minWt = 0;
    DisjointSet ds(V);
    sort(adj.begin(), adj.end());
    for(auto it: adj){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
            minWt += wt;
            ds.UnionBySize(u, v);
        }
    }

    return minWt;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
    };

    int minWt = spanningTree(V, edges);
    cout<<"The sum of all the edge weight inside the minning spanning trees is: "<<minWt<<endl;

    return 0;
}