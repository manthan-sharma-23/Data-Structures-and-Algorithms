#include <cmath>
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
  int count = 0;

  pair<int, int> dfs(TreeNode *root) {
    if (!root)
      return {0, 0};

    auto [leftSum, leftN] = dfs(root->left);
    auto [rightSum, rightN] = dfs(root->right);

    int tSum = leftSum + rightSum + root->val;
    int tN = leftN + rightN + 1;
    if (floor(tSum / tN) == root->val) {
      count++;
    }

    return {tSum, tN};
  }

  int averageOfSubtree(TreeNode *root) {
    dfs(root);
    return count;
  }
};