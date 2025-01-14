#include <queue>
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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return nullptr;

    if (root == p || root == q)
      return root;

    auto left_n = lowestCommonAncestor(root->left, p, q);
    auto right_n = lowestCommonAncestor(root->right, p, q);

    if (left_n && right_n)
      return root;

    if (left_n)
      return left_n;

    return right_n;
  }
};