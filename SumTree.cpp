// Check if a given Binary Tree is Sum Tree

#include <iostream>

using namespace std;

class TreeNode{
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

int isLeaf(TreeNode *node){
    if(node==NULL){
        return 0;
    }
    if(node->left==NULL && node->right==NULL){
        return 1;
    }
    return 0;
}

int isSumTree(TreeNode *root)
{
    int ls = 0;  // for sum of nodes in left subtree
    int rs = 0;  // for sum of nodes in right subtree

    if (root==NULL || isLeaf(root)){
        return 1;
    }

    if(isSumTree(root->left) && isSumTree(root->right)){
        if(root->left==NULL){
            ls = 0;
        }
        else if(isLeaf(root->left)){
            ls = root->left->data;
        }
        else{
            ls = 2 * root->left->data;
        }

        if(root->right==NULL){
            rs = 0;
        }
        else if(isLeaf(root->right)){
            rs = root->right->data;
        }
        else {
            rs = 2 * root->right->data;
        }

        return (root->data == ls + rs);
    }
    return 0;
}

int main(){
    TreeNode *root = new TreeNode (26);
    root->left = new TreeNode(10);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->right  = new TreeNode(3);
    if(isSumTree(root)){
        cout<<"The given tree is a sum tree"<<endl;
    }
    else{
        cout<<"The given tree is not a sum tree"<<endl;
    }
    return 0;
}