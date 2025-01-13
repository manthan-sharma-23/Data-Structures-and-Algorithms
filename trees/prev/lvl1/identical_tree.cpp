#include "tree.cpp"

using namespace std;

bool identicalTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    return ((p->val == q->val) && identicalTree(p->left, q->left) && identicalTree(p->right, q->right));
}