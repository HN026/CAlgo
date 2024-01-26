#include <iostream>
#include <vector>

using namespace std;


class DisjointSet {
    private:
        vector<int> parent;
        vector<int> size;
        int extraedges;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
            extraedges = 0;
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

            if(ulparent_u==ulparent_v){
                extraedges += 1;
                return;
            }

            if(size[ulparent_u]<size[ulparent_v]){
                parent[ulparent_u] = ulparent_v;
                size[ulparent_v] += size[ulparent_u];
            }
            else{
                parent[ulparent_v] = ulparent_u;
                size[ulparent_u] += size[ulparent_v];
            }
        }

        int extraEdges(){
            return extraedges;
        }
};

int connectionRemoval(int n, vector<vector<int>> &connections){
    DisjointSet dj(4);
    int e = connections.size();
    for(int i = 0; i<e; i++){
        dj.UnionBySize(connections[i][0], connections[i][1]);
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(dj.findUltimateParent(i)==i){
            cnt++;
        }
    }

    int extra = dj.extraEdges();
    int ans = cnt-1;
    if(extra>=ans){
        return ans;
    }
    return -1;
}


int main(){
    vector<vector<int>> connections = {
        {0,1},
        {0,2},
        {1,2}, 
    };

    int n = connections.size();
    int ans = connectionRemoval(4, connections);
    cout<<ans<<endl;

    return 0;
}


// Here we will be using the extra edges in the connected components and using that edges we will need to connect the components that are not connected.
// Let's say we have n disconnected components, and to connect them we will be needing n-1 edges. 
// So basically if there are some x number of components that are not connected so we will be needing x-1 edges, condition: extraedges>=x-1 or esle we return -1;