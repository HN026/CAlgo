#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ceil(TreeNode* root, int key){
    if(root==NULL) return -1;
    int ceil = -1;
    TreeNode *temp = root;
    while(temp){
        if(temp->val == key) return key;
        else if(temp->val < key) temp = temp->right;
        else{
            ceil = temp->val;
            temp = temp->left;
        }
    } 
    return ceil;
}

int floor(TreeNode* root, int key){
    if(root==NULL) return -1;
    int floor = -1;
    TreeNode *temp = root;
    while(temp){
        if(temp->val == key) return key;
        else if(temp->val > key) temp = temp->left;
        else{
            floor = temp->val;
            temp = temp->right;
        }
    }
    return floor;
}



int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);

    int cil = ceil(root, 12);
    cout<<"Ceil: "<<cil<<endl;

    int flr = floor(root, 7);
    cout<<"Floor: "<<flr<<endl;
    return 0;
}