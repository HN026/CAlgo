#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int val = 0;
    TreeNode *bstToGst(TreeNode *root) {
        if (root->right)
            bstToGst(root->right);
        val = root->val = val + root->val;
        if (root->left)
            bstToGst(root->left);
        return root;
    }
};

int main() {
    Solution sol = Solution();
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    TreeNode *res = sol.bstToGst(root);
    return 0;
}