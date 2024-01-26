#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    private:
        vector<int> rank;
        vector<int> parent;
    
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUltimateParent(int node){
            if(parent[node]==node){
                return node;
            }
            // In these lines we are implementing path compression.
            return parent[node] = findUltimateParent(parent[node]);
        }

        void UnionByRank(int u, int v){
            int ulparent_u = findUltimateParent(u);
            int ulparent_v = findUltimateParent(v);

            // Means they belong to the same set.
            if(ulparent_u==ulparent_v) return;

            // The set with a smaller rank gets attached to the one with the larger rank
            if(rank[ulparent_u]<rank[ulparent_v]){
                parent[ulparent_u] = ulparent_v;
            }
            else if(rank[ulparent_u]>rank[ulparent_v]){
                parent[ulparent_v] = ulparent_u;
            }
            // If ranks of both are equal we can any of to another and increase the rank by one
            else{
                parent[ulparent_v] = ulparent_u;
                rank[ulparent_u]++;
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);
    // Let's check before adding 3 and 7 if they belong to the same component or not.
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Disjoint"<<endl;
    }

    ds.UnionByRank(3,7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Disjoint"<<endl;
    }

    return 0;
}

// The intuition behind inserting smaller to the larger is to increase the rank/height slowly otherwise it would take more iterations to find the ultimate parent. 

// Because of path compression, we are able to evaluate this in O(4alpha) that makes it O(1), Hence enabling us to check if they are disjoint or not in constant time.

// We don't change the value of rank vector when we are path compressing.

// Size is defined as n+1 so that it works in both 1 and 0 based indexing.
