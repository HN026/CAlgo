#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findSum(TreeNode* root, int& sum) {
    if (root == NULL)
        return;

    if (root->val % 2 == 0 && root->left) {
        if (root->left->left) {
            sum += root->left->left->val;
        }
        if (root->left->right) {
            sum += root->left->right->val;
        }
    }
    if (root->val % 2 == 0 && root->right) {
        if (root->right->left) {
            sum += root->right->left->val;
        }
        if (root->right->right) {
            sum += root->right->right->val;
        }
    }

    findSum(root->left, sum);
    findSum(root->right, sum);
}

int sumEvenGrandparent(TreeNode* root) {
    int sum = 0;
    findSum(root, sum);
    return sum;
}

int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);

    // Find the sum of values of nodes that are the grandchildren of even-valued nodes
    int sum = sumEvenGrandparent(root);
    cout << "Sum: " << sum << endl;

    return 0;
}