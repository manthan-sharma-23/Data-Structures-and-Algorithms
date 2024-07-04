#include "tree.cpp"

using namespace std;

int floor(Node *root, int input)
{
    if (!root)
    {
        return -1;
    }

    int floor = -1;

    while (root)
    {
        if (root->data == input)
        {
            return root->data;
        }

        if (root->data < input)
        {
            floor = root->data;
            root = root->right;
        }else{
            root=root->left;
        }
    }

    return floor;
}