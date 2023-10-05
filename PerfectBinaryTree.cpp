#include<iostream>

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

int findADepth(TreeNode *root){
    int d = 0;
    TreeNode *temp = root;
    while(temp!=NULL){
        d++;
        temp = temp->left;
    }
    return d;
}

bool isPerfectRec(TreeNode *root, int d, int level=0)
{
    if (root==NULL){
        return NULL;
    }
    if (root->left == NULL && root->right == NULL){
        return (d==level+1);
    }
    if(root->left == NULL  || root->right == NULL){
        return false;
    }

    return isPerfectRec(root->left, d, level+1) && isPerfectRec(root->right, d, level+1);
}

bool isPerfect(TreeNode *root){
    int d = findADepth(root);
    return isPerfectRec(root, d);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    if(isPerfect(root)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

