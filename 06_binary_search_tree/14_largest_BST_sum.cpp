#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class NodeValue
{
public:
    int minNode, maxNode, sum;
    bool isBST;
    NodeValue(int minNode, int maxNode, int sum, bool isBST)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution
{
public:
    int maxSum = 0;

    NodeValue func(TreeNode *root)
    {
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        auto left = func(root->left);
        auto right = func(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxNode && root->val < right.minNode)
        {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum,
                true);
        }

        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }

    int maxSumBST(TreeNode *root)
    {
        maxSum = 0; // reset before computation
        func(root);
        return maxSum;
    }
};