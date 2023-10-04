#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *buildTree(TreeNode *root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for Inserting in Left of: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for Inserting in right of: "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void Inorder(TreeNode *root){
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void LevelOrder(TreeNode *root){
    if(root==NULL){
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
    if(q.front()->left!=NULL){
        q.push(q.front()->left);
    }
    if(q.front()->right!=NULL) {
        q.push(q.front()->right);
    }
        q.pop();
    }
}

int main(){
    TreeNode *root = NULL;
    root = buildTree(root);
    Inorder(root);
    cout<<endl;
    LevelOrder(root);
    return 0;
}