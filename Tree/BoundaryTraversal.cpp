#include <bits/stdc++.h>
// Anti clockwise boundary traversal of a binary tree
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode *root){
    if(!root->left && !root->right) return true;
    return false;
}


void addLeftBoundary(TreeNode *root, vector<int> &res){
    TreeNode *cur = root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->val);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBoundary(TreeNode *root, vector<int> &res){
    TreeNode *cur = root->right;
    vector<int> tmp;
    while(cur){
        if(!isLeaf(cur)) tmp.push_back(cur->val);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }

    for(int i = tmp.size()-1; i>=0; i--){
        res.push_back(tmp[i]);
    }
}

void addLeaves(TreeNode *root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }

    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}



vector<int> boundaryTraversal(TreeNode *root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->val);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}



int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->right->left = new TreeNode(18);
    root->right->right = new TreeNode(25);

    vector<int> res = boundaryTraversal(root);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout<<endl;
    
    return 0;
}