#include <iostream>

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
    bool isSym(TreeNode *leftnode, TreeNode* rightnode){
        if(leftnode==nullptr || rightnode==nullptr) return leftnode==rightnode;
        if(leftnode->val!=rightnode->val) return false;
        return isSym(leftnode->left, rightnode->right) && isSym(leftnode->right, rightnode->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return isSym(root->left, root->right);
    }
};

int main() {
    Solution solution;

    TreeNode* symmetricTree = new TreeNode(1,
                                new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                                new TreeNode(2, new TreeNode(4), new TreeNode(3)));

    bool result = solution.isSymmetric(symmetricTree);

    std::cout << "Is the tree symmetric? " << (result ? "Yes" : "No") << std::endl;

    delete symmetricTree;

    return 0;
}
