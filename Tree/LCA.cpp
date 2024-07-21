#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){};
};

TreeNode* LCA(TreeNode *root, TreeNode *p, TreeNode *q){
    if(!root || root->val == p->val || root->val == q->val) return root;

    TreeNode *left = LCA(root->left, p, q);
    TreeNode *right = LCA(root->right, p, q);

    if(left && right) return root;
    return left ? left : right;
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *ans = LCA(root, root->left, root->right);
    cout<<ans->val<<endl;
    return 0;
}