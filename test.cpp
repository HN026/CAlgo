#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q){
    if(!root) return root;

    int i = root->val;
    if(i<p->val && i<q->val) return LCA(root->right, p, q);
    if(i>p->val && i>q->val) return LCA(root->left, p, q);

    return root;
}


int main(){
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right =  new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right =  new TreeNode(5);

    TreeNode *ans = LCA(root, root->left->left, root->left->right->right);
    int k = ans->val;
    cout<<k<<endl;

    return 0;
}