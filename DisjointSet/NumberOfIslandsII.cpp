#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    private:
        vector<int> size;
        vector<int> parent;
    public:
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
            
            if(ulparent_u==ulparent_v) return;

            if(size[ulparent_v]<size[ulparent_u]){
                parent[ulparent_u] = ulparent_v;
                size[ulparent_v] += ulparent_u;
            }
            else{
                parent[ulparent_v] = ulparent_u;
                size[ulparent_u] += ulparent_v;
            }
        }
};

bool isValid(int row, int col, int n, int m){
    if(row>=0 && row<n && col>=0 && col<m) return true;
    return false;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
    DisjointSet ds(n*m);
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int drow[] = {-1, 0, 1 ,0};
    int dcol[] = {0, 1, 0, -1};
    int cnt = 0;
    vector<int> ans;

    for(auto it: operators){
        int row = it[0];
        int col = it[1];
        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;

        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(isValid(nrow, ncol, n, m)){
                if(vis[nrow][ncol]==1){
                    int nodeNo = row*n + col;
                    int adjNode = nrow*n + ncol;
                    if(ds.findUltimateParent(nodeNo)!= ds.findUltimateParent(adjNode)){
                        cnt--;
                        ds.UnionBySize(nodeNo, adjNode);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main(){
    int n = 4;
    int m = 5;
    vector<vector<int>> operators = {
        {0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, 
        {1, 2}, {0, 2}
    };

    vector<int> ans = numOfIslands(n, m, operators);
    for(auto it: ans) cout<<it<<" ";

    return 0;
}