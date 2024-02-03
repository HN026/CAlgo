#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
            if(parent[node]==node) return node;
            return parent[node] = findUltimateParent(parent[node]);
        }

        void UnionBySize(int u, int v){
            int ulparent_u = findUltimateParent(u);
            int ulparent_v = findUltimateParent(v);

            if(ulparent_u == ulparent_v)  return;

            if(size[ulparent_u] < size[ulparent_v]){
                parent[ulparent_u] = ulparent_v;
                size[ulparent_v] += size[ulparent_u];
            }
            else{
                parent[ulparent_v] = ulparent_u;
                size[ulparent_u] += size[ulparent_v]; 
            }
        }
};

int maxRemoved(vector<vector<int>> &stones){
    int n = stones.size();
    int maxRow = 0;
    int minCol = 0;
    for(auto it: stones){
        maxRow = max(maxRow, it[0]);
        minCol = min(minCol, it[1]);
    }

    DisjointSet ds(maxRow + minCol+ 1);
    unordered_map<int, int> stoneNodes;

    for(auto it: stones){
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.UnionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for(auto it: stoneNodes){
        if(ds.findUltimateParent(it.first)==it.first) cnt++;
    }

    return n - cnt;
}

int main(){
    vector<vector<int>> stones = {
        {0,0},
        {0,2},
        {1,1},
        {2,0},
        {2,2}
    };

    int ans = maxRemoved(stones);
    cout<<ans<<endl;

    return 0;
}