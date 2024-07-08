#include "tree.cpp"

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    // find ceil of the val first

    if (!root)
    {
        root = new TreeNode(val);
        return root;
    }

    TreeNode *ceil = nullptr;

    while (root)
    {
        if (root->val == val)
        {
            return root;
        }

        if (root->val < val)
        {
            if (!root->right)
            {
                root->right = new TreeNode(val);
                break;
            }
            root = root->right;
        }
        else
        {
            if (!root->left)
            {
                root->left = new TreeNode(val);
                break;
            }
            root = root->left;
        }
    }

    return root;
}