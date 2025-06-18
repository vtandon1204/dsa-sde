#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int inOrderSuccessor(TreeNode *root, TreeNode *x)
{
    TreeNode *succ = NULL;
    while (root)
    {
        if (root->val > x->val)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (succ)
        return succ->val;
    return -1;
}

int inOrderPredecessor(TreeNode *root, TreeNode *x)
{
    TreeNode *pred = NULL;
    while (root)
    {
        if (root->val < x->val)
        {
            pred = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    if (pred)
        return pred->val;
    return -1;
}