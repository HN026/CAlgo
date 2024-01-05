// /* Recursive Appraoch */

// #include <iostream>
// #include <vector>

// using namespace std;

// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// TreeNode *previous = NULL;

// void FlattenTree(TreeNode *root){
//     if(root==NULL) return;
//     FlattenTree(root->right);
//     FlattenTree(root->left);

//     root->right = previous;
//     root->left = NULL;
//     previous = root;

// int main(){

//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(5);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(4);
//     root->right->right = new TreeNode(6);
//     root->right->right->left = new TreeNode(7);

//     previous = NULL;
//     FlattenTree(root);

//     TreeNode *temp = root;
//     while(temp){
//         cout<<temp->val<<" ";
//         temp = temp->right;
//     }

//     return 0;
// }