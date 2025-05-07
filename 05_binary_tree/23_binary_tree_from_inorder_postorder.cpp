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

int postorderIndex;
unordered_map<int, int> mapping;
TreeNode *build(vector<int> postorder, int start, int end)
{
    if (start > end)
        return NULL;

    // root node will be the last element of the postorder array
    // we will start from the last index and move to the first index of the postorder array
    int rootVal = postorder[postorderIndex--];
    TreeNode *root = new TreeNode(rootVal);

    // getting the index of the root node in the inorder array
    int mid = mapping[rootVal];

    // we will first build the right subtree and then the left subtree
    // because we are traversing the postorder array from the last index to the first index
    root->right = build(postorder, mid + 1, end);
    root->left = build(postorder, start, mid - 1);

    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    mapping.clear();
    // storing the index of inorder elements in a map for O(1) access
    // this will help us to find the index of the root node in inorder array
    for (int i = 0; i < inorder.size(); i++)
    {
        mapping[inorder[i]] = i;
    }

    // postorderIndex will be the last index of the postorder array
    // we will start from the last index and move to the first index of the postorder array
    postorderIndex = postorder.size() - 1;
    return build(postorder, 0, postorder.size() - 1);
}