// Given preorder of a binary tree, calculate its depth(or height) [starting from depth 0]. The preorder is given as a string with two possible characters. 

//     ‘l’ denotes the leaf
//     ‘n’ denotes internal node

// The given tree can be seen as a full binary tree where every node has 0 or two children. The two children of a node can ‘n’ or ‘l’ or mix of both.

#include <iostream>
#include <string>

using namespace std;

int FindDepthRec(string tree, int n, int& index){
    if (index>=n || tree[index]=='l'){
        return 0;
    }

    index++;
    int left = FindDepthRec(tree, n , index);

    index++;
    int right = FindDepthRec(tree,n,index);

    return max(left,right)+1;
}

int FindDepth(string tree, int n)
{
    int index = 0;
    return FindDepthRec(tree, n, index);
}

int main() {
    string tree = "nlnnlll";
    int n = tree.length();
    cout<<FindDepth(tree, n)<<endl;
    return 0;
}