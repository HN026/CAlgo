#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()){
            int mmin = q.front().second;
            int first;
            int last;
            int size = q.size();
            for(int i = 0; i<size; i++){
                int cur_id = q.front().second - mmin;
                TreeNode *temp = q.front().first;
                q.pop();

                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;

                if(temp->left) q.push({temp->left,(long long) 2*cur_id+1});
                if(temp->right) q.push({temp->right,(long long) 2*cur_id+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};

int main() {
    

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->left = new TreeNode(7);

    Solution solution;
    int width = solution.widthOfBinaryTree(root);

    cout << "Width of the binary tree: " << width << endl;

    return 0;
}
