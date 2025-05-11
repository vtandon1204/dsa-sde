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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    map<int, map<int, multiset<int>>> mp;      // (line, (level, multiset of node values))
    queue<pair<TreeNode *, pair<int, int>>> q; // (node, (line, level))
    q.push({root, {0, 0}});                    // line = 0 for root, level = 0 for root

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int line = it.second.first;
        int level = it.second.second;
        mp[line][level].insert(node->val); // insert the node value into the multiset for this line and level
        if (node->left)                    // push left child with line - 1 and level + 1
            q.push({node->left, {line - 1, level + 1}});
        if (node->right) // push right child with line + 1 and level + 1
            q.push({node->right, {line + 1, level + 1}});
    }

    for (auto it : mp)
    {
        vector<int> temp; // to store the values for this line
        for (auto j : it.second)
        { // for each level in this line
            for (auto k : j.second)
            { // for each node value in this level
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}