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
vector<int> morrisPreorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *curr = root;
    TreeNode *pred;
    while (curr)
    {
        if (!curr->left)
        {
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            pred = findPred(curr);
            if (!pred->right)
            {
                pred->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}