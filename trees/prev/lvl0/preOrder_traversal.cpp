#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << endl;

    preorder(root->left);

    preorder(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(8);

    root->left->left = new Node(18);

    root->left->right = new Node(3);

    preorder(root);
    return 0;
}