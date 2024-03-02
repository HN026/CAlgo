#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root->val % 2 == 0) return false;

        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int prev1 = INT_MIN;
            int prev2 = INT_MAX;
            for (int i = 0; i < sz; i++) {
                TreeNode *temp = q.front();
                q.pop();

                if (level % 2 == 0) {
                    if (i != 0 && prev1 >= temp->val) return false;
                    prev1 = temp->val;
                } else {
                    if (i != 0 && prev2 <= temp->val) return false;
                    prev2 = temp->val;
                }

                if ((level % 2 == 0 && temp->val % 2 == 0) || (level % 2 != 0 && temp->val % 2 != 0)) return false;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            level++;
        }

        return true;
    }
};

int main() {
    // Construct the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(2);

    Solution solution;
    bool result = solution.isEvenOddTree(root);
    cout << (result ? "True" : "False") << endl;

    return 0;
}