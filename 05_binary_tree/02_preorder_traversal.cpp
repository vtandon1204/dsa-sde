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

void preorder(TreeNode *root, vector<int> &ans)
{ // Recursive approach 2
    if (root == NULL)
        return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    // Iterative approach - Using stack
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        ans.push_back(node->val);
        if (node->right) // Push right first so that left is processed first
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return ans;
    // Recursive approach 1
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;

    // Recursive approach 2
    vector<int> ans;
    preorder(root, ans);
    return ans;
}
