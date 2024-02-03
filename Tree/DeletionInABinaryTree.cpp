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
            delete root;
            return NULL;
        }
        else{
            return root;
        }
    }
    
    TreeNode * key_node = NULL;
    TreeNode *temp;
    TreeNode *last;
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->key == key) {
            key_node = temp;
        }
        if (temp->left!=NULL) {
            last = temp; // Storing the parent node
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            last = temp;  // Storing the parent node
            q.push(temp->right);
        }
    }

    if (key_node != NULL) {
        key_node->key = temp->key;   // Replacing the key node's data to deepest node's data
        if(last->left == temp) last->left = NULL;
        else if(last->right == temp) last->right = NULL;
        delete temp; // Deleting the deepest node
    }

    return root;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder traversal before deletion: ";
    Inorder(root);
    cout << endl;

    int key = 2;
    root = Deletion(root, key);

    cout << "Inorder traversal after deletion of " << key << ": ";
    Inorder(root);
    cout << endl;

    return 0;
}