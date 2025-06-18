#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &nums, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = s + (e - s) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, s, mid - 1);
    root->right = buildTree(nums, mid + 1, e);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return buildTree(nums, 0, nums.size() - 1);
}