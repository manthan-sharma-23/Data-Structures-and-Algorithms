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
  int diameter = 0;
  int f(TreeNode *root) {
    if (!root)
      return 0;

    int a = f(root->left);
    int b = f(root->right);

    diameter = max(diameter, a + b);

    return max(a, b) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root) {
    f(root);
    return diameter;
  }
};