#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> mp;
        int n = descriptions.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            mp[descriptions[i][1]] = descriptions[i][0];
            st.insert(descriptions[i][1]);
            st.insert(descriptions[i][0]);
        };
        int father = 0;
        for(auto &it: st) if(mp.find(it)==mp.end()) father  = it;

        unordered_map<int, TreeNode*> treeMap;
        treeMap[father] = new TreeNode(father);
        for(auto &it: st) treeMap[it] = new TreeNode(it);

        for(int i = 0; i<n; i++){
            auto temp1 = treeMap[descriptions[i][0]];
            auto temp2 = treeMap[descriptions[i][1]];
            if(descriptions[i][2]==0) temp1->right = temp2;
            else temp1->left = temp2;
        }

        return treeMap[father];
    }
};

// Function to print the binary tree in pre-order traversal
void printPreOrder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {
    Solution solution;
    vector<vector<int>> descriptions = {{20,15,1}, {20,17,0}, {50,20,1}, {50,80,0}, {80,19,1}};
    TreeNode* root = solution.createBinaryTree(descriptions);
    cout << "Pre-order traversal of the created binary tree: ";
    printPreOrder(root);
    cout << endl;
    return 0;
}