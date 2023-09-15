#include <iostream>
#include <queue>

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

bool SearchNode(TreeNode *root, int key){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        if(temp->data==key){
            return true;
        }
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    return false;
}

int main(){
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    int key = 3032;

    if(SearchNode(root, key)){
        cout<<"Yes"<<endl;
    }

    else{
        cout<<"No"<<endl;
    }

    return 0;
}