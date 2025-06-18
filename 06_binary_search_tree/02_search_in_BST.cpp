#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root)
    {
        if (root->val == val)
        {
            return root;
        }
        if (root->val > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
    
    // if (!root) {
    //     return NULL;
    // }
    // if (root->val == val) {
    //     return root;
    // }
    // if (root->val > val) {
    //     return searchBST(root->left, val);
    // } else {
    //     return searchBST(root->right, val);
    // }
}