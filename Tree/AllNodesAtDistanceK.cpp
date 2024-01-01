#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}



vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    int curLevel = 0;
    visited[target] = true;
    while(!q.empty()){
        int size = q.size();
        if(curLevel == k) break;
        curLevel++;
        for(int i = 0; i<size; i++){
            TreeNode *current = q.front();
            q.pop();

            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }

            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }

            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}


int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    int k = 2;
    vector<int> ans = distanceK(root, root->left, k);

    for(auto it: ans) cout<<it<<" ";
    cout<<endl;

    return 0;
}