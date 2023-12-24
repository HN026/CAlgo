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

vector<TreeNode*> f(int start, int end){
    if(start > end){
        return {NULL};
    }

    if(start == end){
        return {new TreeNode(start)};
    }

    vector<TreeNode*> result;

    for(int i = start; i <= end; i++){
        vector<TreeNode*> left = f(start, i - 1);
        vector<TreeNode*> right = f(i + 1, end);

        for(auto l: left){
            for(auto r: right){
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                result.push_back(root);
            }
        }
    }

    return result;
}

vector<TreeNode*> generateTrees(int n){
    if(n == 0){
        return {};
    }
    return f(1, n);
}

int main(){
    int n = 3;
    vector<TreeNode*> ans = generateTrees(n);
    cout << ans.size() << endl;
    return 0;
}