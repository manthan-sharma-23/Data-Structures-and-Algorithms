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

vector<vector<int>> bfs_tree(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            v.push_back(node->data);
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(6);
    root->right = new Node(8);
    root->left->left = new Node(10);
    root->right->left = new Node(4);
    root->left->right = new Node(3);
    root->right->right = new Node(5);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(23);

    vector<vector<int>> ans = bfs_tree(root);

    for (const vector<int> &v : ans)
    {
        for (const int &num : v)
        {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}