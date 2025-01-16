#include <cstdlib>
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
  int ans = 0;

  pair<int, int> dfs(TreeNode *root) {
    if (!root)
      return {1e4, -1e4};

    auto [leftMin, leftMax] = dfs(root->left);
    auto [rightMin, rightMax] = dfs(root->right);

    if (leftMin > rightMin) {
      leftMin = rightMin;
    }
    if (rightMax < leftMax) {
      rightMax = leftMax;
    }

    if (leftMin != 1e4)
      ans = max(ans, abs(leftMin - root->val));

    if (rightMax != -1e4) {
      ans = max(ans, abs(rightMax - root->val));
    }

    return {min(leftMin, root->val), max(rightMax, root->val)};
  }

  int maxAncestorDiff(TreeNode *root) {
    dfs(root);
    return ans;
  }
};