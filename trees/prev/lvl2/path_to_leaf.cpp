#include "tree.cpp"

using namespace std;

vector<vector<int>> paths;

void dfs(TreeNode *node, vector<int> &v)
{
    if (!node)
        return;

    v.push_back(node->val);

    if (!node->left && !node->right)
    {
        paths.push_back(v);
    }
    else
    {
        dfs(node->left, v);
        dfs(node->right, v);
    }

    v.pop_back();
}

vector<vector<int>> Paths(TreeNode *root)
{
    vector<int> path;

    dfs(root, path);

    return paths;
}