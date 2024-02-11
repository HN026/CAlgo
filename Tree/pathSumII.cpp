#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void allpaths(TreeNode *root, int targetSum, vector<int> &temp,
              vector<vector<int>> &ans) {
  if (root == NULL)
    return;

  temp.push_back(root->val);

  if (root->left == NULL && root->right == NULL && root->val == targetSum) {
    ans.push_back(temp);
  } else {
    allpaths(root->left, targetSum - root->val, temp, ans);
    allpaths(root->right, targetSum - root->val, temp, ans);
  }

  temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
  vector<vector<int>> ans;
  vector<int> temp;
  allpaths(root, targetSum, temp, ans);
  return ans;
}

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    vector<vector<int>> result = pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << " are:" << endl;
    for (const auto &path : result) {
        for (const int &val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
