#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class DisjointSet {
    public:
        vector<int> size;
        vector<int> parent;
    
        DisjointSet(int n){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
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
            if(ulparent_u == ulparent_v) return;

            if(size[ulparent_u]<size[ulparent_v]){
                parent[ulparent_u] = ulparent_v;
                size[ulparent_v] += size[ulparent_u];
            }
            else{
                parent[ulparent_v] = ulparent_u;
                size[ulparent_u] += size[ulparent_v];
            }
        }
};

bool isValid(int row, int col, int n){
    return (row>=0 && row<n && col>=0 && col<n);
}

int MaxConnection(vector<vector<int>> &grid){
    int n = grid.size();
    DisjointSet ds(n*n);
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            if(grid[row][col]==0) continue;
            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n) && grid[nrow][ncol]==1){
                    int nodeNo = row * n + col;
                    int nodeAdj = nrow * n + ncol;
                    ds.UnionBySize(nodeNo, nodeAdj);
                }
            }
        }
    }

    int mx = 0;
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            if(grid[row][col]==1) continue;
            unordered_set<int> components;
            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n) && grid[nrow][ncol]==1){
                    components.insert(ds.findUltimateParent(nrow * n + ncol));
                }
            }
            int sizeTotal = 0;
            for(auto it: components){
                sizeTotal += ds.size[it];
            }
            mx = max(mx, sizeTotal+ 1); // +1 because to take the block we are converting to 1 into consideration
        }
    }

    for(int cellNo = 0; cellNo<n*n; cellNo++){
        mx = max(mx, ds.size[ds.findUltimateParent(cellNo)]);
    }

    return mx;
}

int main(){
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0}
    };

    int ans = MaxConnection(grid);
    cout<<ans<<endl;

    return 0;
}