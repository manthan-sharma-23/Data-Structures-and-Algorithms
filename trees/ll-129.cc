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
  int SUM = 0;

  bool isLeaf(TreeNode *node) { return !node->left && !node->right; }

  void dfs(TreeNode *root, int num) {
    if (!root)
      return;

    num = (num * 10) + root->val;

    if (isLeaf(root)) {
      SUM += num;
    }

    dfs(root->left, num);
    dfs(root->right, num);

    num = (num - root->val) / 10;
  }

  int sumNumbers(TreeNode *root) {
    dfs(root, 0);
    return SUM;
  }
};