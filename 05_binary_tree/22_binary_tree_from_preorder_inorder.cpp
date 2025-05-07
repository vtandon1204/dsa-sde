#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

int preorderIndex;
unordered_map<int, int> mapping;
TreeNode *build(vector<int> &preorder, int start, int end)
{
    if (start > end)
        return nullptr;

    // root node will be the first element of the preorder array
    // we will increment the preorderIndex to get the next root node
    int rootVal = preorder[preorderIndex++];
    TreeNode *root = new TreeNode(rootVal);

    // getting the index of the root node in the inorder array
    int mid = mapping[rootVal];

    // we will first build the left subtree and then the right subtree
    // because we are traversing the preorder array from the first index to the last index
    root->left = build(preorder, start, mid - 1);
    root->right = build(preorder, mid + 1, end);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    mapping.clear();

    // storing the index of inorder elements in a map for O(1) access
    // this will help us to find the index of the root node in inorder array
    for (int i = 0; i < inorder.size(); i++)
    {
        mapping[inorder[i]] = i;
    }

    // preorderIndex will be the first index of the preorder array
    // we will start from the first index and move to the last index of the preorder array
    preorderIndex = 0;
    return build(preorder, 0, inorder.size() - 1);
}