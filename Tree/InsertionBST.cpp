#include <bits/stdc++.h>

using namespace std;

class BST {
    int data;
    BST *left;
    BST *right;
    public: 
    BST(){
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    BST(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    BST *Insert(BST *root, int value){
        if(!root){
            return new BST(value);
        }
        if(value > root->data){
            root->right = Insert(root->right, value);
        }
        else if(value < root->data){
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
};

int main(){
    BST *root = NULL;
    BST *b = new BST();
    root = b->Insert(root, 50);
    b->Insert(root, 30);
    b->Insert(root, 20);
    b->Insert(root, 40);
    b->Insert(root, 70);
    b->Insert(root, 60);
    b->Insert(root, 80);

    b->Inorder(root);
    cout<<endl;
    return 0;
}