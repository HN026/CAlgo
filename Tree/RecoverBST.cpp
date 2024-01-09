#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
}

class Solution {
    private:
        TreeNode *prev;
        TreeNode *first;
        TreeNode *middle;
        TreeNode *last;
    public:
    void inorder(TreeNode *root){
        if(root==NULL) return;

        inorder(root->left);
        if(prev && root->val<prev->val){
            // first violation: 
            if(first==NULL){
                first = prev;
                middle = root;
            }

            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode *root){
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }

}
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2); 

    Solution solution;
    solution.recoverTree(root);
    return 0;
}