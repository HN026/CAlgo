#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool validCheck(TreeNode *root, long long int lowerBound, long long int UpperBound){
    if(root==NULL) return true;

    if(root->left){
        if(root->left->val >= root->val || root->left->val <= lowerBound || root->left->val >=UpperBound) return false;
    }

    if(root->right){
        if(root->right->val <=root->val || root->right->val >=UpperBound || root->right->val <= lowerBound) return false;
    }
    // or we can only use if(root->val <= lowerBound || root->val >= UpperBound) return false; but the above lines would make it run faster.

    return validCheck(root->left, lowerBound, root->val) && validCheck(root->right, root->val, UpperBound);
}

bool isValidBST(TreeNode* root) {
    long long int min = LLONG_MIN, max = LLONG_MAX;
    return validCheck(root, min, max);
}

int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    bool isBST = isValidBST(root);
    cout << "Is the tree a valid BST? " << (isBST ? "Yes" : "No") << endl;
    return 0;
}