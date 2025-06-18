#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool func(TreeNode *node, long minVal, long maxVal)
{
    if (!node)
        return true;
    if (node->val >= maxVal || node->val <= minVal)
        return false;
    return func(node->left, minVal, node->val) &&
           func(node->right, node->val, maxVal);
}
bool isValidBST(TreeNode *root)
{
    if (!root)
        return true;
    return func(root, LONG_MIN, LONG_MAX);
}