#include <iostream>

using namespace std;

class TreeNode{
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

int isSibling(TreeNode *root, TreeNode *a, TreeNode *b){
    if(root==NULL){
        return 0;
    }

    return ((root->left==a && root->right == b)
    || (root->left == b && root->right == a)
    || (isSibling(root->left, a, b))
    || (isSibling(root->right, a, b)));
}

int Level(TreeNode *root, TreeNode *ptr, int level)
{
    if(root==NULL){
        return 0;
    }
    if(root==ptr){
        return level;
    }

    int l = Level(root->left, ptr, level+1);
    if(l!=0){
        return l;
    }
    return Level(root->right, ptr, level+1);
}

int isCousin(TreeNode *root, TreeNode *a, TreeNode *b)
{
    if((Level(root, a, 1) == Level(root, b, 1))
    && !(isSibling(root, a, b))){
        return 1;
    }
    return 0;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new  TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    TreeNode *a, *b;
    a = root->left->left;
    b = root->right->right;

    cout<<isCousin(root, a, b)<<endl;
    return 0;
}