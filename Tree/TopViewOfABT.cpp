#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

vector<int> topView(TreeNode *root){
    vector<int> ans;
    if(!root) return ans;
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();

        TreeNode *node = temp.first;
        int vertical = temp.second;

        if(mp.find(vertical)==mp.end()) mp[vertical] = node->val;

        if(node->left) q.push({node->left, vertical-1});
        if(node->right) q.push({node->right, vertical + 1});
    }

    for(auto it: mp){
        ans.push_back(it.second);
    }

    return ans;
}


int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->right = new TreeNode(7);
    root->left->left->right->left = new TreeNode(9);
    root->left->left->right->left->left = new TreeNode(10);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(8);
    root->right->right->left->right = new TreeNode(11);

    vector<int> ans = topView(root);

    for(auto it: ans){
        cout<<it<<" ";
    }


    return 0;
}