#include "tree.cpp"

using namespace std;

int findCeil(Node *root, int input)
{
    if (!root)
        return -1;

    int ceil = -1;

    while (root)
    {
        if (root->data == input)
        {
            return root->data;
        }

        if (root->data < input)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}