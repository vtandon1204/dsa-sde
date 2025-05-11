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

void postorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    // Iterative approach - Using stack
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (!st.empty() || node != NULL)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    reverse(ans.begin(), ans.end()); // Reverse the result to get postorder
    return ans;

    // Recursive approach 1

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);

    ans.insert(ans.end(), left.begin(), left.end());   // Insert left subtree values
    ans.insert(ans.end(), right.begin(), right.end()); // Insert right subtree values
    ans.push_back(root->val);

    // Recursive approach 2
    vector<int> ans;
    postorder(root, ans);
    return ans;
}