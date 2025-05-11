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

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, long long>> q; // queue of pairs (node, index)
    q.push({root, 0});                    // push the root node with index 0
    // level order traversal

    while (!q.empty())
    {
        int size = q.size();
        int mini = q.front().second; // get the index of the first node in the current level
        long long first, last;
        for (int i = 0; i < size; i++)
        {
            TreeNode *currNode = q.front().first;        // get the current node
            long long currInd = q.front().second - mini; // get the index of the current node
            q.pop();
            if (i == 0)
                first = currInd; // store the index of the first node
            if (i == size - 1)
                last = currInd; // store the index of the last node
            if (currNode->left)
                q.push({currNode->left, 2 * currInd + 1}); // left child index
            if (currNode->right)
                q.push({currNode->right, 2 * currInd + 2}); // right child index
        }
        ans = max(ans, int(last - first + 1)); // update the maximum width
    }
    return ans;
}