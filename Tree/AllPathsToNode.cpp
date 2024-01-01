#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){};
};


void f(TreeNode* root, vector<int> &path, vector<vector<int>> &ans){
    if(!root->left && !root->right){
        path.push_back(root->val);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    
    if(root->left){
        path.push_back(root->val);
        f(root->left, path, ans);
        path.pop_back();
    }

    if(root->right){
        path.push_back(root->val);
        f(root->right, path, ans);
        path.pop_back();
    }
}


vector<vector<int>> AllPaths(TreeNode *root){
    vector<vector<int>> ans;
    vector<int> path;
    if(!root) return ans;
    f(root, path, ans);
    return ans;
}




int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = AllPaths(root);

    for(auto it: ans){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }

    return 0;
}