#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
    public:
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int key){
      this->key = key;
      left = NULL;
      right = NULL;
    }
};

void Inorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->key<<" ";
    Inorder(root->right);
}

// During Traversal, it keeps track of the deepest node 'temp', the node to be deleted 'key_node', and the parent of the deepest node 'last'


TreeNode* Deletion(TreeNode *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->key == key){
            return NULL;
        }
        else{
            return NULL;
        }
    }
    
    TreeNode * key_node = NULL;
    TreeNode *temp;
    TreeNode *last;
    queue<TreeNode *> q;
    q.push(root);

}


int main() {
    return 0;
}