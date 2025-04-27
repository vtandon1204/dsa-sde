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

bool isLeaf(TreeNode* node){
    if(!node->left && !node->right){
        return true;
    }
    return false;
}

void leftBoundary(TreeNode* node, vector<int> & ans){
    TreeNode* curr = node->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void leaves(TreeNode* node, vector<int> & ans){
    if(isLeaf(node)) {
        ans.push_back(node->val);
        return;
    }
    if(node->left) leaves(node->left,ans);
    if(node->right) leaves(node->right,ans);
}

void rightBoundary(TreeNode* node, vector<int> & ans){
    TreeNode* curr = node->right;
    vector<int> rev;
    while(curr){
        if(!isLeaf(curr)) rev.push_back(curr->val);
        if(curr->left) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=rev.size()-1;i>=0;i--){
        ans.push_back(rev[i]);
    }
}

vector <int> boundary(TreeNode* root){
    vector<int> ans;

    if(!root) return ans;

    if(!isLeaf(root)) ans.push_back(root->val);

    leftBoundary(root,ans);
    leaves(root,ans);
    rightBoundary(root,ans);

    return ans;
}