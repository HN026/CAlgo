#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class DisjointSet {
  public:
    vector<int> size;
    vector<int> parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int uparent_u = findUltimateParent(u);
        int uparent_v = findUltimateParent(v);

        if (uparent_u == uparent_v)
            return;

        if (size[uparent_u] < size[uparent_v]) {
            parent[uparent_u] = uparent_v;
            size[uparent_v] += size[uparent_u];
        } else {
            parent[uparent_v] = uparent_u;
            size[uparent_u] += size[uparent_v];
        }
    }
};

void primeFactors(int n, int i, unordered_map<int, vector<int>> &mp) {
    if(n%2==0) mp[2].push_back(i);
    while(n%2==0) n = n/2;
    for(int x = 3; x<=n; x+=2){
        if(n%x==0) mp[x].push_back(i);
        while(n%x==0) n = n/x;
    }
    if(n>2) mp[n].push_back(i);
}

bool findAllTraversal(vector<int> &nums){
    int n = nums.size();
    DisjointSet ds(n);
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i<n; i++) primeFactors(nums[i], i, mp);

    for(auto &it: mp){
        auto &v = it.second;
        for(int i = 1; i<v.size(); i++){
            ds.UnionBySize(v[0], v[i]);
        }
    }

    for(int i = 0; i<n; i++){
        if(ds.size[i]==n) return true;
    }

    return false;
}

int main() {

    vector<int> nums = {2, 3, 6};
    bool ans = findAllTraversal(nums);
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}