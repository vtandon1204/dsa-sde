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

void changeTree(TreeNode *root)
{
    if (!root)
        return;

    int child_sum = 0;
    // getting the sum of left and right child
    if (root->left)
        child_sum += root->left->val;
    if (root->right)
        child_sum += root->right->val;

    //
    if (child_sum >= root->val)
    {
        // if the sum of child is greater than or equal to the root node, then we will set the root node to the sum of child
        root->val = child_sum;
    }
    else
    {
        // if the sum of child is less than the root node, then we will set the child node to the root node
        if (root->left)
            root->left->val = root->val;
        if (root->right)
            root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    // while returning back to the root node, we will set the root node to the sum of child nodes
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;
    if (root->left || root->right)
        root->val = tot;
    return;
}