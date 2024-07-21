#include <iostream>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    string lcaToStart, lcaToEnd;
public:
    TreeNode* findLCA(TreeNode *root, int p, int q){
        if(!root || root->val == p || root->val == q) return root;
        TreeNode *left = findLCA(root->left, p, q);
        TreeNode *right = findLCA(root->right, p, q);
        if(left && right) return root;
        return left ? left : right;
    }

    void dfs(TreeNode *lcaNode, string &pathString, int startValue, int destValue){
        if(!lcaNode) return;
        if(lcaNode->val == startValue) lcaToStart = pathString;
        if(lcaNode->val == destValue) lcaToEnd = pathString;
        pathString.push_back('L');
        dfs(lcaNode->left, pathString, startValue, destValue);
        pathString.pop_back();
        pathString.push_back('R');
        dfs(lcaNode->right, pathString, startValue, destValue);
        pathString.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = findLCA(root, startValue, destValue);
        string pathString = "";
        dfs(lca, pathString, startValue, destValue);
        for(auto &ch: lcaToStart) ch = 'U';
        return lcaToStart + lcaToEnd;
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create the binary tree
    // Example tree:
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    TreeNode *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    Solution sol;
    string directions = sol.getDirections(root, 5, 1);
    cout << "Directions: " << directions << endl;

    // Clean up the tree
    // Note: In a real application, you should properly delete all allocated nodes to avoid memory leaks.
    return 0;
}