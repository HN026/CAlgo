#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void buildTree(int node, int start, int end, vector<int> &arr, vector<int> &tree){
    if(start>end) return;
    if(start==end){
        tree[node] = arr[start];
        return;
    }

    int mid = start + (end-start)/2;
    buildTree(2*node+1, start, mid, arr, tree);
    buildTree(2*node+2, mid+1, end, arr, tree);
    tree[node] = max(tree[2*node+1], tree[2*node+2]);

}

int query(int node, int start, int end, int l, int r, vector<int> &tree){
    // Completely lies inside the range
    if(start>=l && end<=r) return tree[node];
    // Completely outside the range
    if(start>r || end<l) return INT_MIN;
    // Partially inside and partially outside
    int mid = start + (end-start)/2;
    int left = query(2*node+1, start, mid, l, r, tree);
    int right = query(2*node+2, mid+1, end, l, r, tree);
    return max(left, right);
}

int main(){
    vector<int> arr = {};
    int n = arr.size();
    vector<int> tree(4*n, 0);

    buildTree(0, 0, n-1, arr, tree);

    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<query(0, 0, n-1, l, r, tree)<<endl;
    }

    return 0;
}