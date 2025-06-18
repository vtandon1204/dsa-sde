#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int preorderInd = 0;
TreeNode *func(vector<int> &preorder, int lower, int higher)
{
    if (preorderInd >= preorder.size())
        return NULL;
    int rootVal = preorder[preorderInd];
    if (rootVal < lower || rootVal > higher)
        return NULL;
    TreeNode *root = new TreeNode(rootVal);
    preorderInd++;
    root->left = func(preorder, lower, rootVal - 1);
    root->right = func(preorder, rootVal + 1, higher);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    return func(preorder, INT_MIN, INT_MAX);
}