// The diameter/width of a tree is defined as the number of nodes on the longest path between the two end nodes.
// It is not necessary that it passes through the node.
// Time complexity: O(N^2)
// Auxilary Space: O(N) for call stack

#include <iostream>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int height(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right) + 1;
}

int diameter(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout<<diameter(root)<<endl;
    return 0;
}