#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Brute Force
// -> storing the inorder traversal of BST in an array
// -> then return the [k-1] index value because inorder traversal of BST is a sorted array
void inorderTraversal(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    return inorder[k - 1];
}
int kthLargest(TreeNode *root, int k)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    return inorder[inorder.size() - k];
}

// Optimal Approach
// -> perform inorder traversal, at every visited node increment the counter
// -> when counter == k, store the value in answer
// -> return this answer
void inorder(TreeNode *root, int cnt, int k, int ans)
{
    if (!root || cnt >= k)
    {
        return;
    }
    inorder(root->left, cnt, k, ans);
    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    inorder(root->right, cnt, k, ans);
}
void Reverseinorder(TreeNode *root, int cnt, int k, int ans)
{
    if (!root || cnt >= k)
    {
        return;
    }
    Reverseinorder(root->right, cnt, k, ans);
    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    Reverseinorder(root->left, cnt, k, ans);
}
int kthSmallest(TreeNode *root, int k)
{
    int ans;
    inorder(root, 0, k, ans);
    return ans;
}
int kthSmallest(TreeNode *root, int k)
{
    int ans;
    Reverseinorder(root, 0, k, ans);
    return ans;
}