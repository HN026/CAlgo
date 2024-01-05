#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(root==NULL) return "";
       string s = "";
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();

        if(temp==NULL) s.append("#,");
        else s.append(to_string(temp->val)+",");

        if(temp){
            q.push(temp->left);
            q.push(temp->right);
        }
       }

       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        queue<TreeNode*> q;
        getline(s,str,',');
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();

            getline(s, str, ','); // Delimiting character
            if(str == "#"){
                temp->left = NULL;
            }
            else{
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }

            getline(s, str, ',');
            if(str == "#"){
                temp->right = NULL;
            }
            else{
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }

        return root;
    }
};

void inorder(TreeNode *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}

int main() {
    // Example usage
    Codec ser, deser;

    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Serializing the tree
    string serialized_tree = ser.serialize(root);
    cout << "Serialized tree: " << serialized_tree << endl;

    // Deserializing the tree
    TreeNode* deserialized_tree = deser.deserialize(serialized_tree);
    inorder(deserialized_tree);

    // You can perform operations on the deserialized tree as needed

    return 0;
}
