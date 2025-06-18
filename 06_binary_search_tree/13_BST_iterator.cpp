#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator
{
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }
    void inorder(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        inorder(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};