#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* build(vector<int>&postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp){
    if(postEnd > postStart || inStart > inEnd) return NULL;

    TreeNode *root = new TreeNode(postorder[postStart]);

    int inRoot = mp[root->val];
    int numsRight = inEnd - inRoot;

    root->left = build(postorder, postStart-numsRight-1, postEnd, inorder, inStart, inRoot-1, mp);
    root->right = build(postorder, postStart-1, postStart-numsRight, inorder, inRoot+1, inEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder){
    unordered_map<int, int> mp;
    for(int i = 0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }
    TreeNode* root = build(postorder, postorder.size()-1, 0, inorder, 0, inorder.size()-1, mp);
    return root;
}

void Inorder(TreeNode *root){
    if(root==NULL) return;

    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

int main(){
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {3,9,15,20,7};

    TreeNode* root = buildTree(inorder, postorder);
    Inorder(root);
    return 0;
}