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

void FindDepthAndHeight(TreeNode *root, int k){
    if(root==NULL){
        return;
    }
    int depth = -1;
    int height = -1;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i<n; i++){
            TreeNode *first = q.front();
            q.pop();
            if(first->data == k){
                depth = level;
            }
            if(first->left!=NULL){
                q.push(first->left);
            }
            if(first->right!=NULL){
                q.push(first->right);
            }
        }
        level++;
    }
    height = level - depth -1;
    cout<<"Depth: "<<depth<<endl;
    cout<<"Height: "<<height<<endl;
}

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(25);
    root->left->right->right = new TreeNode(45);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);

    int k = 25;

    FindDepthAndHeight(root, k);

    return 0;
}