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
    if (root == nullptr)
      return nullptr;

    if (root == p || root == q)
      return root;

    TreeNode *leftN = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightN = lowestCommonAncestor(root->right, p, q);

    if (leftN != nullptr && rightN != nullptr) {
      return root;
    }

    if (leftN != nullptr)
      return leftN;

    return rightN;
  }
};