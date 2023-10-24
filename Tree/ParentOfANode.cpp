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

void ReturnParent(TreeNode *root, int key, int parent){
    if(root==NULL){
        return;
    }
    if(root->data==key){
        cout<<parent<<endl;
    }
    else{
        ReturnParent(root->left, key, root->data);
        ReturnParent(root->right, key, root->data);
    }
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int key = 4;
    ReturnParent(root, key, -1);
    return 0;
}