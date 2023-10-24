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

int maxDepth(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    else{
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);

        if(ldepth > rdepth) {
            return ldepth+1;
        }
        else{
            return rdepth+1;
        }
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<"Height of tree is: "<<maxDepth(root)<<endl;
    return 0;
}