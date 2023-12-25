#include <iostream>
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

    void allpaths(TreeNode *root, string l,vector<string> &ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(l);
            return;
        }

        if(root->right==NULL && root->left!=NULL){
            l += "->";
            l += to_string(root->left->val);
            allpaths(root->left, l, ans);
        }
        else if(root->left==NULL && root->right!=NULL){
            l += "->";
            l += to_string(root->right->val);
            allpaths(root->right, l, ans);
        }
        else{
            l+= "->";
            string original = l;
            l += to_string(root->left->val);
            allpaths(root->left, l, ans);
            l = original;
            l += to_string(root->right->val);
            allpaths(root->right, l, ans);
            l = original;
        }
    }



    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string l = "";
        if(root==NULL){
            return {""};
        }
        l += to_string(root->val);
        allpaths(root, l, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;


    vector<string> paths = solution.binaryTreePaths(root);

    cout << "Binary Tree Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
