#include "tree.cpp";

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;

    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode *> q;

    q.push(root);

    bool leftOrRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            root = q.front();

            q.pop();

            int index = leftOrRight ? i : size - 1 - i;

            ans[index] = root->val;

            if (root->left)
            {
                q.push(root->left);
            }

            if (root->right)
            {
                q.push(root->right);
            }
        }
        leftOrRight = !leftOrRight;
        result.push_back(ans);
    }

    return result;
}