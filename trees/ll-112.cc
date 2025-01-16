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
  bool isLeaf(TreeNode *root) { return !root->left && !root->right; }

  bool dfs(TreeNode *root, int targetSum) {
    if (!root)
      return false;

    targetSum -= root->val;

    if (isLeaf(root) && targetSum == 0) {
      return true;
    }
    return dfs(root->left, targetSum) || dfs(root->right, targetSum);
  }

  bool hasPathSum(TreeNode *root, int targetSum) {
    return dfs(root, targetSum);
  }
};