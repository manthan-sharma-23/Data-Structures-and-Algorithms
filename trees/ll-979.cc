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
  int moves = 0;

  int dfs(TreeNode *root) {
    if (!root)
      return 0;

    int leftN = dfs(root->left);
    int rightN = dfs(root->right);

    int need = leftN + rightN;

    moves += need;

    int required = 1 - (root->val - need);

    return required;
  }

  int distributeCoins(TreeNode *root) {
    dfs(root);
    return moves;
  }
};