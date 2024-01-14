#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(NULL), right(NULL){};
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

void diff(TreeNode *root, int mini, int maxi, int &Difference){
    if(!root) return;

    Difference = max(Difference, max(abs(root->val-mini), abs(maxi-root->val)));
    mini = min(root->val, mini);
    maxi = max(root->val, maxi);
    diff(root->left, mini, maxi, Difference);
    diff(root->right, mini, maxi, Difference);
}

int maxAncestorDiff(TreeNode* root) {
    if(!root) return 0;
    int Difference = 0;
    diff(root, root->val, root->val, Difference);
    return Difference;
}

int main(){
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    int ans = maxAncestorDiff(root);
    cout<<ans<<endl;


    return 0;
}