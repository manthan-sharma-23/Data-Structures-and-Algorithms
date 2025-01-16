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
  int longestPath = 0;

  pair<int, int> dfs(TreeNode *root) {
    if (!root)
      return {0, 0};

    auto [_, leftL] = dfs(root->left);
    auto [rightL, __] = dfs(root->right);

    if (root->left)
      leftL++;
    if (root->right)
      rightL++;

    longestPath = max(max(leftL, rightL), longestPath);

    return {leftL, rightL};
  }

  int longestZigZag(TreeNode *root) {
    dfs(root);
    return longestPath;
  }
};