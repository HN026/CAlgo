#include <iostream>
#include <queue>

using namespace std;


class TreeNode {
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

class BinaryTree {
    private:
    TreeNode *root;
    public:
    BinaryTree() {
        root = NULL;
    }

    void insertValue(int value){
        root = insertValueRecursion(root, value);
    }

    TreeNode *insertValueRecursion(TreeNode *root, int value){
        if(root==NULL){
            root = new TreeNode(value);
        }
        else if (root->key>=value){
            root->left = insertValueRecursion(root->left, value);
        }
        else{
            root->right = insertValueRecursion(root->right, value);
        }
        return root;
    }

    void createTree(int arr[], int n){
        for(int i = 0; i<n; i++){
            insertValue(arr[i]);
        }
    }

void levelOrder() {
        if(root==NULL){
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            cout<<q.front()->key<<" ";
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
};

int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    BinaryTree tree;
    tree.createTree(arr,n);
    tree.levelOrder();
    return 0;
}
