#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool dfs(ListNode* curr, TreeNode* root) {
        if (curr == NULL) return true;
        if (root == NULL) return false;
        if (curr->val == root->val) {
            return dfs(curr->next, root->left) || dfs(curr->next, root->right);
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Helper function to create a binary tree from a vector (level order)
TreeNode* createBinaryTree(const vector<int>& values) {
    if (values.empty()) return nullptr;
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;
        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int main() {
    // Example test case
    vector<int> listValues = {4, 2, 8};
    vector<int> treeValues = {1, 4, 4, -1, 2, 2, -1, 1, -1, 6, 8, -1, -1, -1, -1, 1, 3};

    ListNode* head = createLinkedList(listValues);
    TreeNode* root = createBinaryTree(treeValues);

    Solution solution;
    bool result = solution.isSubPath(head, root);
    cout << (result ? "True" : "False") << endl;

    // Clean up memory
    // Note: In a real application, you should also delete the linked list and tree nodes to avoid memory leaks.
    return 0;
}