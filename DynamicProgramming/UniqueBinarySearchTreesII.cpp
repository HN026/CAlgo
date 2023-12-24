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

vector<TreeNode*> f(int start, int end, vector<vector<vector<TreeNode*>>> &dp){
    if(start > end){
        return {NULL};
    }

    if(dp[start][end].size() != 0){
        return dp[start][end];
    }

    if(start == end){
        return dp[start][end] = {new TreeNode(start)};
    }

    vector<TreeNode*> result;

    for(int i = start; i <= end; i++){
        vector<TreeNode*> left = f(start, i - 1, dp);
        vector<TreeNode*> right = f(i + 1, end, dp);

        for(auto l: left){
            for(auto r: right){
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                result.push_back(root);
            }
        }
    }

    return dp[start][end] = result;
}

vector<TreeNode*> generateTrees(int n){
    if(n == 0){
        return {};
    }

    vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2));
    return f(1, n, dp);
}

int main(){
    int n = 3;
    vector<TreeNode*> ans = generateTrees(n);
    cout << ans.size() << endl;
    return 0;
}