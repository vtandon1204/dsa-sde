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

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (!root)
        return "";
    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
            s.append("null,");
        else
            s.append(to_string(node->val) + ',');
        if (node)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "null")
            node->left = NULL;
        else
        {
            TreeNode *leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if (str == "null")
            node->right = NULL;
        else
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}