#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, int& sum) {
    if(root == nullptr) return;
    traverse(root->right, sum);
    sum += root->val;
    root->val = sum;
    traverse(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    traverse(root, sum);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    root = convertBST(root);

    return 0;
}