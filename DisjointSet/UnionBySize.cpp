#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    private:
        vector<int> sze; // size vector
        vector<int> parent;
    public:
        DisjointSet(int n){
            sze.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++) parent[i] = i;
        }

        int findUltimateParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]); 
            // Path compression along with finding Ultimate Parent.
        }

        void UnionBySize(int u, int v){
            int ulparent_u = findUltimateParent(u);
            int ulparent_v = findUltimateParent(v);

            if(ulparent_u == ulparent_v) return;

            if(sze[ulparent_u]<sze[ulparent_v]){
                parent[ulparent_u] = ulparent_v;
                sze[ulparent_v] += sze[ulparent_u];
            }
            // we can do it in only one else loop but I'm programming an else if and else for better understand
            else if(sze[ulparent_u]>sze[ulparent_v]){
                parent[ulparent_v] = ulparent_u;
                sze[ulparent_u] += sze[ulparent_v];
            }
            // If both are of same size, we can connect any one to any.
            else {
                parent[ulparent_v] = ulparent_u;
                sze[ulparent_u] += sze[ulparent_v];
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Disjoint"<<endl;
    }

    ds.UnionBySize(3,7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Disjoint"<<endl;
    }

    return 0;
}