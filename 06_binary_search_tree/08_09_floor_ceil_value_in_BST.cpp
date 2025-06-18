#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> floorCeilOfBST(TreeNode *root, int key)
{
    vector<int> ans;
    int ceilVal = -1;
    int floorVal = -1;

    TreeNode *tmp = root;

    // Find ceil
    while (tmp)
    {
        if (tmp->val == key)
        {
            ceilVal = tmp->val;
            break;
        }
        if (tmp->val < key)
        {
            tmp = tmp->right;
        }
        else
        {
            ceilVal = tmp->val;
            tmp = tmp->left;
        }
    }

    tmp = root; // Reset tmp for floor search

    // Find floor
    while (tmp)
    {
        if (tmp->val == key)
        {
            floorVal = tmp->val;
            break;
        }
        if (tmp->val > key)
        {
            tmp = tmp->left;
        }
        else
        {
            floorVal = tmp->val;
            tmp = tmp->right;
        }
    }

    ans.push_back(floorVal);
    ans.push_back(ceilVal);
    return ans;
}