#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int height(TreeNode *root) {
        if (!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

    int findBottomLeftValue(TreeNode *root) {
        if (!root->left && !root->right)
            return root->val;
        int level = 1;
        int ht = height(root);
        queue<TreeNode *> q;
        q.push(root);
        int ans = root->val;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode *temp = q.front();
                q.pop();
                if (level == ht && i == 0) {
                    ans = temp->val;
                }
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            level++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    cout << "Bottom left value: " << sol.findBottomLeftValue(root) << endl;
    return 0;
}