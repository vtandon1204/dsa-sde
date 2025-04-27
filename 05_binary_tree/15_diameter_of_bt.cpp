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

// int height(TreeNode *root)
// {
//     if (!root)
//         return 0;
//     int lh = height(root->left);
//     int rh = height(root->right);
//     return 1 + max(lh, rh);
// }

pair<int, int> func(TreeNode *root)
{
    if (!root)
        return {0, 0};

    pair<int, int> left = func(root->left);
    pair<int, int> right = func(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameterOfBinaryTree(TreeNode *root)
{
    // if (!root)
    //     return 0;

    // int op1 = diameterOfBinaryTree(root->left);
    // int op2 = diameterOfBinaryTree(root->right);
    // int op3 = height(root->left) + height(root->right) + 1;

    // return max(op1, max(op2, op3)) - 1;

    pair<int, int> ans;
    ans = func(root);
    return ans.first - 1;
}