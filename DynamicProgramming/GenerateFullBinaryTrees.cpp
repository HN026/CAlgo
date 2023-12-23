// Recursion only

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<TreeNode*> allPossibleFBT(int n){
    vector<TreeNode*> result;
    if(n==1){
        result.push_back(new TreeNode(0));
        return result;
    }

    n-=1; // Account for the root node;

    for(int i = 1; i<=n; i+=2){
        vector<TreeNode*> left = allPossibleFBT(i);
        vector<TreeNode*> right = allPossibleFBT(n-i);

        for(auto l: left){
            for(auto r: right){
                TreeNode *root = new TreeNode(0);
                root->left = l;
                root->right = r;
                result.push_back(root);
            }
        }
    }

    return result;
}


int main(){
    int n = 7;
    
        vector<TreeNode*> ans = allPossibleFBT(n);
    
        for(auto root: ans){
            cout<<root->val<<endl;
        }
    
        return 0;
}