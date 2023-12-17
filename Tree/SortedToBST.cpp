#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *sortedToBST(vector<int> &nums, int start, int end){
    if(start > end ){
        return  NULL;

        int mid = start + (end-start)/2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = sortedToBST(nums, start, mid-1);
        root->right = sortedToBST(nums, mid+1, end);

        return root;
    }
}

void preOrder(TreeNode *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();

    TreeNode *root = sortedToBST(arr, 0, n-1);
    preOrder(root);

    return 0;
}