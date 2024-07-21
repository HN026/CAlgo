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
    int numOfGoodLeafPairs;

  public:
    vector<int> dfs(TreeNode *node, int distance) {
        if (!node)
            return {};
        if (!node->left && !node->right)
            return {1};

        vector<int> leftv = dfs(node->left, distance);
        vector<int> rightv = dfs(node->right, distance);

        for (auto lv : leftv) {
            for (auto rv : rightv) {
                if (lv + rv <= distance)
                    numOfGoodLeafPairs++;
            }
        }

        vector<int> parentv;
        for (auto lv : leftv)
            if (lv + 1 <= distance)
                parentv.push_back(lv + 1);
        for (auto rv : rightv)
            if (rv + 1 <= distance)
                parentv.push_back(rv + 1);

        return parentv;
    }

    int countPairs(TreeNode *root, int distance) {
        numOfGoodLeafPairs = 0;
        dfs(root, distance);
        return numOfGoodLeafPairs;
    }
};

TreeNode *newNode(int val) {
    return new TreeNode(val);
}

int main() {
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution sol;
    int distance = 3;
    int result = sol.countPairs(root, distance);
    cout << "Number of good leaf node pairs: " << result << endl;

    return 0;
}