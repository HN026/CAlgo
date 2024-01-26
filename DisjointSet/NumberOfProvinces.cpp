#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUltimateParent(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void UnionBySize(int u, int v){
            int ulparent_u = findUltimateParent(u);
            int ulparent_v = findUltimateParent(v);
            if(ulparent_u == ulparent_v) return;

            if(size[ulparent_u]<size[ulparent_v]){
                parent[ulparent_u] = ulparent_v;
                size[ulparent_v] += size[ulparent_u];
            }
            else{
                parent[ulparent_v] = ulparent_u;
                size[ulparent_u] += ulparent_v;
            }
        }
};

int NumberOfProvinces(vector<vector<int>> &edges, int n){
    DisjointSet dj(3);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(edges[i][j]==1){
                dj.UnionBySize(i,j);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(dj.findUltimateParent(i)==i) cnt++;
    }

    return cnt;
}



int main(){

    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};

    int a = NumberOfProvinces(isConnected, 3);
    cout<<a<<" "<<endl;
    return 0;
}