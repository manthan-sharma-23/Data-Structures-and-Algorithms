#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int inorder_traversal(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int a = inorder_traversal(root->left);  // Traverse the left subtree
    int b = inorder_traversal(root->right); // Traverse the right subtree
    return 1 + a + b;                       // Visit the root node
}

int inorder_traversal_height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int a = inorder_traversal_height(root->left);  // Traverse the left subtree
    int b = inorder_traversal_height(root->right); // Traverse the right subtree
    return max(a, b) + 1;                          // Visit the root node
}

void postorder_traversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << endl;
}

int main()
{
    // Creating a simple binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << inorder_traversal_height(root) << endl;

    return 0;
}
