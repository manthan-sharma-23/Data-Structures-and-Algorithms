#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

bool dfs(TreeNode *node, TreeNode *p, vector<TreeNode *> &v)
{
    if (!node)
    {
        return false;
    }

    v.push_back(node);
    if (node == p)
    {
        return true;
    }

    if (dfs(node->left, p, v) || dfs(node->right, p, v))
    {
        return true;
    }

    v.pop_back();
    return false;
}

vector<TreeNode *> findPathToNode(TreeNode *root, TreeNode *p)
{
    vector<TreeNode *> v;
    if (!p || !root)
    {
        return v;
    }

    if (!dfs(root, p, v))
    {
        v.clear();
    }

    return v;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(16);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(9);
    root->right->left->right->left = new TreeNode(10);
    root->right->left->right->right = new TreeNode(12);

    vector<TreeNode *> v = findPathToNode(root, root->right->left->right->left);

    for (TreeNode *a : v)
    {
        cout << a->val << " ";
    }
    cout << endl;
    return 0;
}