#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

void recursion(TreeNode *root, vector<int> &ans, int level){
    if(root==NULL) return;
    if(ans.size()==level) ans.push_back(root->val);
    recursion(root->right, ans, level+1);
    recursion(root->left, ans, level+1);
}

vector<int> rightView(TreeNode *root){
    vector<int> ans;
    recursion(root, ans, 0);
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> ans = rightView(root);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}