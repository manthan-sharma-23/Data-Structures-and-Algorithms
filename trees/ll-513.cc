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
  int leftMost = 1e5;
  int currlevel = 0;

  void dfs(TreeNode *root, int level) {
    if (!root)
      return;

    if (!root->left && !root->right) {
      if (leftMost == 1e5 || level > currlevel) {
        leftMost = root->val;
        currlevel = level;
      }
    }

    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }

  int findBottomLeftValue(TreeNode *root) {
    dfs(root, 0);

    return leftMost;
  }
};