#include <climits>
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
    int mini = INT_MAX;
    TreeNode *prev = NULL;

  public:
    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root->left);
        if (prev != NULL) {
            mini = min(mini, abs(root->val - prev->val));
        }
        prev = root;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode *root) {
        inorder(root);
        return mini;
    }
};

int main() {
    Solution solution;

    // Create a binary search tree: 4 -> 2 -> 6 -> 1 -> 3 -> NULL -> NULL
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int result = solution.minDiffInBST(root);

    cout << "Minimum difference in BST: " << result << endl;

    // Delete the BST to avoid memory leak
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}