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

void inorder(TreeNode *root, vector<int> &ans)
{ // Recursive approach 2
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
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
    return ans;

    // Recursive approach 1
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    vector<int> left = inorderTraversal(root->left);
    vector<int> right = inorderTraversal(root->right);

    ans.insert(ans.end(), left.begin(), left.end()); // Insert left subtree values
    ans.push_back(root->val);
    ans.insert(ans.end(), right.begin(), right.end()); // Insert right subtree values
    return ans;
    
    // Recursive approach 2
    vector<int> ans;
    inorder(root, ans);
    return ans;

    return ans;
}