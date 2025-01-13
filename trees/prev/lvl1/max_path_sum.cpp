
#include "tree.cpp"
using namespace std;

class MaxPathSum
{
public:
    MaxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        traverse(root, maxi);
        // return maxi;
        cout << "Max Path sum of the given binary tree  :: ";
        cout << maxi << endl;
    }

private:
    int traverse(TreeNode *root, int &maxi)
    {
        if (!root)
        {
            return 0;
        }

        int left = max(0, traverse(root->left, maxi));
        int right = max(0, traverse(root->right, maxi));

        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }
};
