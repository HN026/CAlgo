#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = mp[root->val];
    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
    root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);

    return root;
}


TreeNode* buildTree(vector<int>&preorder, vector<int> &inorder){
    unordered_map<int, int> mp;

    for(int i = 0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }

    TreeNode *root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);

    return root;
}

void Inorder(TreeNode *root){
    if(root==NULL) return;

    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}


int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,15,20,7};

    TreeNode *root = buildTree(preorder, inorder);
    Inorder(root);
    cout<<endl;


    return 0;
}