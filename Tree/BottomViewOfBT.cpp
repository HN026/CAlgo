#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

vector<int> bottomView(TreeNode *root){
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    vector<int> ans;
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int level = temp.second;

        mp[level] = node->val;

        if(node->left) q.push({node->left, level-1});
        if(node->right) q.push({node->right, level+1});
    }

    for(auto it: mp){
        ans.push_back(it.second);
    }

    return ans;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans = bottomView(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}