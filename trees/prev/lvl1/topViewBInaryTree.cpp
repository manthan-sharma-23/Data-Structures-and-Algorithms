#include "tree.cpp"

using namespace std;

vector<int> topView(TreeNode *root)
{
    // Your code here
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    queue<pair<int, TreeNode *>> q;

    map<int, int> mp;

    if (!root)
    {
        return ans;
    }

    q.push({0, root});

    while (!q.empty())
    {
        root = q.front().second;

        int x = q.front().first;

        mp[x] = root->val;

        if (root->left)
        {
            q.push({x + 1, root->left});
        }
        if (root->right)
        {
            q.push({x + 1, root->right});
        }
        q.pop();
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}