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

TreeNode *findPred(TreeNode *curr)
{
    TreeNode *pred = curr->left;
    while (pred->right && pred->right != curr)
    {
        pred = pred->right;
    }
    return pred;
}
vector<int> morrisInorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *curr = root;
    TreeNode *pred;
    while (curr)
    {
        if (!curr->left)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            pred = findPred(curr);
            if (!pred->right)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}