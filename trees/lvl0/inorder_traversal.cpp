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

void inorder_traversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder_traversal(root->left);  // Traverse the left subtree
    cout << root->data << " ";      // Visit the root node
    inorder_traversal(root->right); // Traverse the right subtree
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

    cout << "In-order traversal: ";
    inorder_traversal(root);
    cout << endl;

    // Clean up the memory (optional for this simple example)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
