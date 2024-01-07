#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class BSTIterator{
    private:
        stack<TreeNode *> myst;
    public:
        void pushAll(TreeNode* root){
            while(root){
                myst.push(root);
                root = root->left;
            }
        }

        BSTIterator(TreeNode *root){
            pushAll(root);
        }

        int next(){
            TreeNode *node = myst.top();
            myst.pop();
            pushAll(node->right);
            return node->val;
        }

        bool hasNext(){ 
            return !myst.empty();
        }
};

int main() {
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() << " ";
    
    return 0;
}