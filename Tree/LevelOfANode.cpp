#include <iostream>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int LevelOfANode(TreeNode *root, int k)
{
    int level = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        for (int i = 0; i<q.size(); i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->data == k)
            {
                return level + 1;
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        level++;
    }
    return -1;
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    cout << LevelOfANode(root, 4) << endl;

    return 0;
}