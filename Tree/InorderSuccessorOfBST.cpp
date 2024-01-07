#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

TreeNode* InorderSuccessor(TreeNode* root, int key){
    if(root==NULL) return root;
    TreeNode *successor = NULL;
    while(root){
        if(root->val <= key){
            root = root->right;
        }
        else if(root->val > key){
            successor = root;
            root = root->left;
        }
    }
    return successor;
}




int main(){

    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(14);

    TreeNode *ans = InorderSuccessor(root, 8);
    int k;
    if(ans==NULL) k = -1;
    else k = ans->val;
    cout<<k<<endl;

    return 0;
}