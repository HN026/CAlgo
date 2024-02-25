#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root, vector<int> &a){
    if(!root) return;

    inorder(root->left, a);
    a.push_back(root->val);
    inorder(root->right, a);
}

TreeNode* increasingBST(TreeNode* root) {
    if(!root) return root;

    vector<int> a;
    inorder(root, a);
    TreeNode *newRoot = new TreeNode(a[0]);
    TreeNode *k = newRoot;
    for(int i = 1; i<a.size(); i++){
        TreeNode *temp = new TreeNode(a[i]);
        k->right = temp;
        k->left = NULL;
        k = temp;
    }

    return newRoot;
}

void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    TreeNode* newRoot = increasingBST(root);

    printInorder(newRoot);

    return 0;
}