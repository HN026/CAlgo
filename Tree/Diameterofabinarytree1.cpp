// The diameter/width of a tree is defined as the number of nodes on the longest path between the two end nodes.
// It is not necessary that it passes through the node.
// Time complexity: O(N^2)
// Auxilary Space: O(N) for call stack
     

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};


int height(TreeNode *root){
    if(root==NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right)+1;
}


int DiameterOfTheTree(TreeNode *root){
    if(root==NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int leftDiameter = DiameterOfTheTree(root->left);
    int rightDiameter = DiameterOfTheTree(root->right);

    return max(left+right, max(leftDiameter, rightDiameter));
}


int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    int ans = DiameterOfTheTree(root);
    cout<<height(root)<<endl;
    cout<<ans<<endl;

    return 0;
}