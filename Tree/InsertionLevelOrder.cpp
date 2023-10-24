#include<iostream>
#include<queue>

using namespace std;

class TreeNode{
    public:
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

TreeNode *InsertNode(TreeNode *root, int key){
    if(root==NULL){
        root = new TreeNode(key);
        return root;
    }

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        else{
            temp->left = new TreeNode(key);
            return root;
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        else{
            temp->right = new TreeNode(key);
            return root;
        }
    }
}

void Inorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->key<<" ";
    Inorder(root->right);
}

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(11);
    root->left->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(8);

    cout<<"Inorder Traversal before Insertion: "<<endl;
    Inorder(root);
    cout<<endl;
    int key = 12;
    root = InsertNode(root, key);
    cout<<"Inorder Traversal after Insertion: "<<endl;
    Inorder(root);
    cout<<endl;
    return 0;
}


