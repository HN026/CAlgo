// Time complexity O(N)
// The first approach can be optimised by calculating the height in the same recursion rather than calling a height() funciton 
// seperately.

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

int diameter(TreeNode *root, int *height) {
    int lh = 0;
    int rh = 0;

    int ldiameter = 0;
    int rdiameter = 0;

    if(root==NULL){
        *height = 0;
        return 0;
    }

    ldiameter = diameter(root->left, &lh);
    rdiameter = diameter(root->right, &rh);

    *height = max(lh,rh)+1;
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = 0;
    cout<<diameter(root, &height)<<endl;
    return 0;
}