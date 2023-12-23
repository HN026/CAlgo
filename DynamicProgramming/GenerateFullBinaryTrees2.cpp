// Optimised using memoization

#include <bits/stdc++.h>

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

vector<TreeNode*> f(int n, unordered_map<int, vector<TreeNode*>> &memo){
    vector<TreeNode*> result;
    if(n==1){
        result.push_back(new TreeNode(0));
        return result;
    }

    if(memo.find(n)!=memo.end()) return memo[n];

    n-=1; // Account for the root node;
    for(int i = 1; i<=n; i+=2){
        vector<TreeNode*> left = f(i, memo);
        vector<TreeNode*> right = f(n-i, memo);

        for(auto l: left){
            for(auto r: right){
                TreeNode *root = new TreeNode(0);
                root->left = l;
                root->right =r;
                result.push_back(root);
            }
        }
    }

    return memo[n+1] = result;
}





vector<TreeNode*> allPossibleFBT(int n){
    unordered_map<int, vector<TreeNode*>> memo;
    return f(n, memo);
}


int main(){
    int n = 7;
    
        vector<TreeNode*> ans = allPossibleFBT(n);
    
        for(auto root: ans){
            cout<<root->val<<endl;
        }
    
        return 0;
}