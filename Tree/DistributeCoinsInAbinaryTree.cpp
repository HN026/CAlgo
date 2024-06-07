#include <cmath>
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
    int steps = 0;

  public:
    int dfs(TreeNode *root) {
        if (root == NULL)
            return 0;

        int leftRequired = dfs(root->left);
        int rightRequired = dfs(root->right);

        steps += abs(leftRequired) + abs(rightRequired);
        return root->val + leftRequired + rightRequired - 1;
    }

    int distributeCoins(TreeNode *root) {
        dfs(root);
        return steps;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    Solution s;
    cout << "Number of steps to distribute coins: " << s.distributeCoins(root) << endl;

    return 0;
}
