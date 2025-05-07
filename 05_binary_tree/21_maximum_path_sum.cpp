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

int maxSum = INT_MIN;
int func(TreeNode *root)
{
    if (!root)
        return 0;
    int leftSum = func(root->left);
    int rightSum = func(root->right);
    maxSum = max(maxSum, (root->val + leftSum + rightSum));
    int val = max(leftSum, rightSum) + root->val;
    return val;
}
int maxPathSum(TreeNode *root)
{
    func(root);
    return maxSum;
}