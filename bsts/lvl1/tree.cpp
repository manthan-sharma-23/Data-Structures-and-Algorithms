#include <bits/stdc++.h>

using namespace std;

// Leetcode
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

// GFG
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        data = data;
        left = right = nullptr;
    }
};