#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* f(vector<int> &preorder, int &index, int upperBound){
    if(index==preorder.size() || preorder[index]>upperBound) return NULL;

    TreeNode *root = new TreeNode(preorder[index]);
    index++;
    root->left = f(preorder, index, root->val);
    root->right = f(preorder, index, upperBound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return f(preorder, index, INT_MAX);
}

void printInorder(TreeNode* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode* root = bstFromPreorder(preorder);
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    return 0;
}