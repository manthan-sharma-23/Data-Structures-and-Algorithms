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
  int count = 0;

  void dfs(TreeNode *root) {
    if (!root)
      return;
    count++;
    if (root->left)
      dfs(root->left);

    if (root->right)
      dfs(root->right);
  }

  int countNodes(TreeNode *root) {
    dfs(root);
    return count;
  }
};