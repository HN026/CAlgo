#include <iostream>
#include <unordered_set>
#include <vector>
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
    unordered_set<int> st;
    vector<TreeNode *> ans;

  public:
    void dfs(TreeNode *root, bool isRoot) {
        if (!root)
            return;

        if (st.find(root->val) != st.end()) {
            dfs(root->left, true);
            dfs(root->right, true);
        } else {
            if (isRoot)
                ans.push_back(root);

            TreeNode *leftNode = root->left;
            TreeNode *rightNode = root->right;

            if (leftNode && st.find(root->left->val) != st.end())
                root->left = NULL;
            if (rightNode && st.find(root->right->val) != st.end())
                root->right = NULL;

            dfs(leftNode, false);
            dfs(rightNode, false);
        }
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        st.insert(to_delete.begin(), to_delete.end());
        dfs(root, true);
        return ans;
    }
};

// Helper function to create a new TreeNode
TreeNode *newNode(int val) {
    return new TreeNode(val);
}

// Function to print the trees in the forest
void printForest(vector<TreeNode *> forest) {
    for (auto tree : forest) {
        // Simple preorder traversal for demonstration
        if (tree) {
            cout << tree->val << " ";
            if (tree->left)
                cout << "L:" << tree->left->val << " ";
            if (tree->right)
                cout << "R:" << tree->right->val << " ";
            cout << endl;
        }
    }
}

int main() {
    // Create the binary tree
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution sol;
    vector<int> to_delete = {3, 5};
    vector<TreeNode *> forest = sol.delNodes(root, to_delete);

    printForest(forest);

    // Note: In a real application, you should properly delete all allocated nodes to avoid memory leaks.
    return 0;
}