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

    BST* Search(BST *root, int key){
        if(!root || root->data==key) return root;
        if(key>root->data) return Search(root->right, key);
        return Search(root->left, key);
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

    int key = 2023;
    if(b->Search(root, key) == NULL) {
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }

    return 0;
}