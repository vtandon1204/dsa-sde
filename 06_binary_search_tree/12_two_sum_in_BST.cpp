#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool search(TreeNode *node, TreeNode *ignore, int k)
{
    while (node)
    {
        if (node->val == k & node != ignore)
            return true;
        if (node->val > k)
            node = node->left;
        else
            node = node->right;
    }
    return false;
}
bool func(TreeNode *node, TreeNode *root, int k)
{
    if (!node)
        return false;
    int need = k - node->val;
    if (search(root, node, need))
        return true;
    return func(node->left, root, k) || func(node->right, root, k);
}
bool fundTarget(TreeNode *root, int k)
{
    return func(root, root, k);
}