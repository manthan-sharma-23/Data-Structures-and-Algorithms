#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        val = val;
        left = right = nullptr;
    }
};

TreeNode *searchInBST(TreeNode *root, int num)
{
    while (root && root->val == num)
    {
        root = num < root->val ? root->left : root->right;
    }
    return root;
}

int MaxInBinaryTree(TreeNode *root) {
    while(root->right){
        root=root->right;
    }
    return root->val;
}

int MinInBinaryTree(TreeNode *root) {
    while(root->left){
        root=root->left;
    }
    return root->val;
}