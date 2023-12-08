#include <bits/stdc++.h>

using namespace std;

class BST {
    public:
    int data;
    BST *left;
    BST *right;
    BST(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void storeNodes(BST *root, vector<BST*> &nodes){
    if(!root) return;

    storeNodes(root->left, nodes);
    nodes.push_back(root);
    storeNodes(root->right, nodes);
}

BST* buildTreeUtil(vector<BST*> &nodes, int start, int end){
    if(start>end) return NULL;
    int mid = start + (end -start)/2;
    BST *root = nodes[mid];

    root->left = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);

    return root;
}

BST* buildBST(BST *root)
{
    vector<BST*> nodes;
    storeNodes(root, nodes);

    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}

void Preorder(BST *root){
    if(!root) return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

int height(BST *root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}   

bool isBalanced(BST *root){
    if(!root) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)>1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
}


int main(){
    BST* root = new BST(10);
    root->left = new BST(8);
    root->left->left= new BST(7);
    root->left->left->left = new BST(6);
    root->left->left->left->left = new BST(5);

    root = buildBST(root);
    Preorder(root);
    cout<<endl;
    if(isBalanced(root)) cout<<"Balanced"<<endl;
    else cout<<"NotBalanced"<<endl;
    return 0;
}