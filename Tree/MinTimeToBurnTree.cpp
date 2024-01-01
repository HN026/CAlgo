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

TreeNode* markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track, int start){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();
        if(current->val == start) res = current;

        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
    return res;
}


int timeToBurnTree(TreeNode *root, int start){
    unordered_map<TreeNode*, TreeNode*> parent_track;
    TreeNode* st = markParents(root, parent_track, start);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(st);
    visited[st] = true;
    int maxi = 0;
    while(!q.empty()){
        int size = q.size();
        int fl = 0;
        for(int i = 0; i<size; i++){
            TreeNode *current = q.front();
            q.pop();
            
            if(current->left && !visited[current->left]){
                fl = 1;
                q.push(current->left);
                visited[current->left] = true;
            }

            if(current->right && !visited[current->right]){
                fl = 1; 
                q.push(current->right);
                visited[current->right] = true;
            }

            if(parent_track[current] && !visited[parent_track[current]]){
                fl = 1;
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
        if(fl) maxi++;
    }

    return maxi;

}



int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int start = 3;
    int ans = timeToBurnTree(root, start);
    cout<<ans<<endl;

    return 0;
}