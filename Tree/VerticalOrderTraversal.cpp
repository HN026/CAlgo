#include <bits/stdc++.h>

using namespace std;

// Queue(node, vertical, level);
// map<vertical, map<level, multiset<int>>  because on one level, there can be multiple nodes.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode *root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        TreeNode *node = temp.first;
        int vert = temp.second.first;
        int level = temp.second.second;
        nodes[vert][level].insert(node->val);
        if(node->left) q.push({node->left, {vert-1, level+1}});
        if(node->right) q.push({node->right, {vert+1, level+1}});
    }

    vector<vector<int>> ans;
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}



int main(){

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = verticalTraversal(root);

    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }


    return 0;
}