#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL){} 
};

void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *current = q.front();
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

int amountOfTime(TreeNode *root, TreeNode *start){
    if(root==NULL) return 0;
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    visited[start] = true;
    int maxi = 0;
    q.push(start);
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
#include <unordered_map>
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
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    int ans = amountOfTime(root, root->right);
    cout<<ans<<endl;

    return 0;
}