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

vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<pair<TreeNode *, int>> q; // (node, line)
    map<int, int> mp;               // (line, node->val)
    q.push({root, 0});              // line = 0 for root

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end()) // only add the first node at this line
            mp[line] = node->val;
        if (node->left) // push left child with line - 1
            q.push({node->left, line - 1});
        if (node->right) // push right child with line + 1
            q.push({node->right, line + 1});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second); // add the values in order of their lines
    }
    return ans;
}