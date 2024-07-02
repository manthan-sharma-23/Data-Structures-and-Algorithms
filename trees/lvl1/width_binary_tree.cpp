
#include "tree.cpp"

using namespace std;

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;

    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int mmin = q.front().second;

        int first, last;

        for (int i = 0; i < size; i++)
        {
            int curr_id = q.front().second - mmin;
            root = q.front().first;
            q.pop();

            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;

            if (root->left)
            {
                q.push({root->left, 2 * curr_id + 1});
            }

            if (root->right)
                q.push({root->right, 2 * curr_id + 2});
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main()
{
    return 0;
}