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
void Preorder(TreeNode *node, int level, vector<int> &ans)
{
    if (!node)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(node->val);
    }
    Preorder(node->left, level + 1, ans);
    Preorder(node->right, level + 1, ans);
}
void reversePreorder(TreeNode *node, int level, vector<int> &ans)
{
    if (!node)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(node->val);
    }
    reversePreorder(node->right, level + 1, ans);
    reversePreorder(node->left, level + 1, ans);
}
vector<int> leftSideView(TreeNode *root)
{
    vector<int> ans;
    Preorder(root, 0, ans);
    return ans;
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    reversePreorder(root, 0, ans);
    return ans;
}