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

// int height(TreeNode* root) {
//     if (!root)
//         return 0;
//     int left = height(root->left);
//     int right = height(root->right);
//     return max(left, right) + 1;
// }

pair<bool, int> func(TreeNode *root)
{
    if (!root)
        return {true, 0};

    pair<bool, int> left = func(root->left);
    pair<bool, int> right = func(root->right);

    bool cond = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    ans.first = (left.first && right.first && cond);
    
    return ans;
}
bool isBalanced(TreeNode *root)
{
    // if (!root)
    //     return true;
    // bool left = isBalanced(root->left);
    // bool right = isBalanced(root->right);
    // bool cond = abs(height(root->left) - height(root->right)) <= 1;
    // return (left && right && cond);

    pair<bool, int> ans = func(root);
    return ans.first;
}