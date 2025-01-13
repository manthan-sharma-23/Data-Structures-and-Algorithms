#include "tree.cpp"

using namespace std;

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> qu;
    qu.push({root, {0, 0}});

    while (!qu.empty())
    {
        auto p = qu.front();
        qu.pop();
        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left)
        {
            qu.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            qu.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }

        ans.push_back(col);
    }

    return ans;
}