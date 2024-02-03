#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DisjointSet{
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
            if(parent[node]==node){
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }
    
        void UnionBySize(int u, int v){
            int ulparent_u = findUltimateParent(u);
            int ulparent_v = findUltimateParent(v);
            
            if (ulparent_u == ulparent_v) return;

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

vector<vector<string>> accountsMerge(vector<vector<string>> &details){
    int n = details.size();
    DisjointSet ds(n);
    unordered_map<string, int> mapMailNode;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<details[i].size(); j++){
            string mail = details[i][j];
            if(mapMailNode.find(mail)==mapMailNode.end()){
                mapMailNode[mail] = i;
            }
            else{
                ds.UnionBySize(mapMailNode[mail], i);
            }
        }
    }

    vector<string> mergeMail[n];
    for(auto it: mapMailNode){
        string mail = it.first;
        int node = ds.findUltimateParent(it.second);
        mergeMail[node].push_back(mail);
    }

    vector<vector<string>> ans;

    for(int i = 0; i<n; i++){
        if (mergeMail[i].size()==0) continue;
        sort(mergeMail[i].begin(), mergeMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for(auto it: mergeMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {

    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    vector<vector<string>> ans = accountsMerge(accounts);
    for (auto acc : ans) {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}