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

bool getPath(TreeNode *root, vector<TreeNode *> &ans, TreeNode *x)
{
    if (!root)
        return false;

    ans.push_back(root);

    if (root == x)
        return true;

    if (getPath(root->left, ans, x) || getPath(root->right, ans, x))
        return true;

    ans.pop_back();
    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // vector<TreeNode *> path1, path2;
    // getPath(root, path1, p);
    // getPath(root, path2, q);

    // int n = min(path1.size(), path2.size());
    // TreeNode *lca = nullptr;

    // for (int i = 0; i < n; i++)
    // {
    //     if (path1[i] == path2[i])
    //         lca = path1[i];
    //     else
    //         break;
    // }
    // return lca;

    if (!root || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (!left)
        return right;
    else if (!right)
        return left;
    else
        return root;
}