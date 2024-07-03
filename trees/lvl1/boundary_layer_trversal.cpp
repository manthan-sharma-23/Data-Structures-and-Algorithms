#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class BoundaryLayerTraversal
{
private:
    void leftTraversal(TreeNode *root, vector<int> &v)
    {
        TreeNode *curr = root->left;

        while (curr)
        {

            if (!isLeaf(curr))
            {
                v.push_back(curr->val);
            }
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    void rightTraversal(TreeNode *root, vector<int> &v)
    {
        TreeNode *curr = root->right;
        vector<int> temp;

        while (curr)
        {
            if (!isLeaf(curr))
            {
                temp.push_back(curr->val);
            }

            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        for (int i = temp.size() - 1; i > -1; i--)
        {
            v.push_back(temp[i]);
        }
    }

    void leavesTraversal(TreeNode *root, vector<int> &v)
    {
        if (isLeaf(root))
        {
            v.push_back(root->val);
            return;
        }

        if (root->left)
        {
            leavesTraversal(root->left, v);
        }
        if (root->right)
        {
            leavesTraversal(root->right, v);
        }
    }

    bool isLeaf(TreeNode *node)
    {
        return !node->left && !node->right;
    }

public:
    BoundaryLayerTraversal(TreeNode *root)
    {
        vector<int> v;

        v.push_back(root->val);

        leftTraversal(root, v);
        leavesTraversal(root, v);
        rightTraversal(root, v);

        for (int n : v)
        {
            cout << n << "   ";
        }
        cout << endl;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(9);
    root->right->left->right->left = new TreeNode(10);
    root->right->left->right->right = new TreeNode(12);

    BoundaryLayerTraversal *b = new BoundaryLayerTraversal(root);
    return 0;
}