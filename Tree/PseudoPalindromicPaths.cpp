#include <iostream>
#include <vector>

using namespace std;

// TC O(n)
// SC O(n) -> Recursive stack space for Inorder traversal

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to count the number of pseudo-palindromic paths
int countOdd(vector<int> &hashmap) {
    int cnt = 0;
    for (int i = 0; i < hashmap.size(); i++) {
        if (hashmap[i] & 1)
            cnt++;
    }
    return cnt;
}

// Depth-first search function
int dfs(TreeNode *root, vector<int> &hashmap) {
    if (!root)
        return 0;

    hashmap[root->val]++;

    if (!root->left && !root->right) {
        int cnt = countOdd(hashmap);
        hashmap[root->val]--;

        return (cnt <= 1) ? 1 : 0;
    }

    int leftCount = dfs(root->left, hashmap);
    int rightCount = dfs(root->right, hashmap);

    hashmap[root->val]--;

    return leftCount + rightCount;
}

// Main function to find pseudo-palindromic paths
int pseudoPalindromicPaths(TreeNode *root) {
    vector<int> hashmap(10, 0);
    return dfs(root, hashmap);
}

// Example usage
int main() {
    // Constructing a sample binary tree
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    // Calling the function and printing the result
    cout << "Number of pseudo-palindromic paths: " << pseudoPalindromicPaths(root) << endl;

    // Cleanup: Freeing the allocated memory for the tree nodes (not mandatory in this example)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
