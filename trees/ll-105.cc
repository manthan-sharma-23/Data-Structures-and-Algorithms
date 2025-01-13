#include <cstddef>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int idx = 0;
  TreeNode *f(vector<int> &preorder, vector<int> &inorder, int start, int end) {
    if (start >= end)
      return nullptr;

    auto root = new TreeNode(preorder[idx]);
    idx++;

    int i = start;
    while (i < end && inorder[i] != root->val)
      i++;

    root->left = f(preorder, inorder, start, i);
    root->right = f(preorder, inorder, i + 1, end);

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return f(preorder, inorder, 0, inorder.size());
  }
};
