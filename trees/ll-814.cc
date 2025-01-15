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
  bool dfs(TreeNode *root) {
    if (!root)
      return false;

    auto leftSubTree = dfs(root->left);
    auto rightSubTree = dfs(root->right);

    if (!leftSubTree)
      root->left = nullptr;

    if (!rightSubTree)
      root->right = nullptr;

    if (leftSubTree || rightSubTree || root->val == 1) {
      return true;
    } else {
      return false;
    }
  }

  TreeNode *pruneTree(TreeNode *root) {

    if (dfs(root))
      return root;
    else
      return nullptr;
  }
};