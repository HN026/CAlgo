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

BST* Insert(BST *root, int value){
    if(!root){
        return new BST(value);
    }
    if(value>root->data){
        root->right = Insert(root->right, value);
    }
    else{
        root->left = Insert(root->left, value);
    }
    return root;
}

void Inorder(BST *root){
    if(!root){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void PreOrder(BST *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(BST *root){
    if(!root){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

BST* Delete(BST *root, int key){
    if(!root) return root;
    if(key>root->data){
        root->right = Delete(root->right, key);
        return root;
    }
    else if(key<root->data){
        root->left = Delete(root->left, key);
        return root;
    }

    // if one of the children is empty
    if(!root->left){
        BST* temp = root->right;
        delete root;
        return temp;
    }

    else if(!root->right){
        BST* temp = root->left;
        delete root;
        return temp;
    }
    else {
        BST *succParent = root;
        BST *succ = root->right;
        while(succ->left){
            succParent = succ;
            succ = succ->left;
        }

        //Once the in-order successor has been found, it needs to be removed from its current position in the tree. If the successor has a right child, that child is moved to the successor's position. This is done with these lines
        if(succParent!=root){
            succParent->left = succ->right;
        }
        else{
            succParent->right = succ->right;
        }

        root->data = succ->data;
        delete succ;
        return root;
    }
}

int main(){
    BST *root = NULL;
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 60);
    Insert(root, 20);
    Insert(root, 35);
    Insert(root, 56);
    Insert(root, 80);
    Insert(root, 55);

    Inorder(root);
    cout<<endl;

    root = Delete(root, 50);
    Inorder(root);
    cout<<endl;

    Insert(root, 90);
    Inorder(root);
    cout<<endl;

    return 0;
}