#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

vector<int> preOrder(TreeNode *root)
{
    vector<int> v;

    stack<TreeNode *> st;

    st.push(root);

    while (!st.empty())
    {
        TreeNode *root = st.top();

        v.push_back(root->data);

        st.pop();

        if (root->right != nullptr)
        {
            st.push(root->right);
        }
        if (root->left != nullptr)
        {
            st.push(root->left);
        }
    }

    return v;
}

vector<int> inorder(TreeNode *root)
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }

    stack<TreeNode *> st;

    st.push(root);

    while (!st.empty())
    {

        if (root->left != nullptr)
        {
            st.push(root->left);
        }
        
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);

    return 0;
}



        //     1
        //    / \
        //   2   3
        //  / \  /
        // 4  5  7
        //    /   \
        //    6    8