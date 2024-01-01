#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void changeTree(TreeNode *root){
    if(root==NULL) return;
    int child = 0;
    if(root->left) child += root->left->val;
    if(root->right) child += root->right->val;

    if(child>=root->val) root->val = child;
    else{
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if(root->left) tot += root->left->val;
    if(root->right) tot += root->right->val;
    if(root->left || root->right) root->val = tot;
}

void Inorder(TreeNode *root){
    if(root==NULL) return;

    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}


int main(){
    TreeNode *root = new TreeNode(40);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(40);

    changeTree(root);
    Inorder(root);
    cout<<endl;

    changeTree(root);
    return 0;
}

