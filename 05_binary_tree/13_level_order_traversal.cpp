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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> row = {};
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL) // if we reach the end of a level
        {
            if (!row.empty()) // if the row is not empty, push it to ans
            {
                ans.push_back(row);
                row.clear();
            }
            if (!q.empty()) // if the queue is not empty, push NULL to mark the end of the next level
            {
                q.push(NULL);
            }
        }
        else
        {
            row.push_back(temp->val); // add the current node's value to the row
            if (temp->left)           // if left
                q.push(temp->left);
            if (temp->right) // if right
                q.push(temp->right);
        }
    }
    return ans;
}