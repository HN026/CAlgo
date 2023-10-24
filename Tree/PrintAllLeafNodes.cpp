#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void PrintAllLeafNodes (TreeNode *root) {
    if (root==NULL){
        return;
    }

    if(root->left==NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    if(root->left!=NULL){
        PrintAllLeafNodes(root->left);
    }

    if(root->right!=NULL){
        PrintAllLeafNodes(root->right);
    }
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    PrintAllLeafNodes(root);
    return 0;
}