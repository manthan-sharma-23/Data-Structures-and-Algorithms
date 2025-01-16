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
  int allVisitedMask = (1 << 9) - 1;
  vector<int> visited = vector<int>(9, 0);
  int number = 0;

  bool isLeaf(TreeNode *root) { return !root->left && !root->right; }

  void dfs(TreeNode *root) {
    if (!root)
      return;

    visited[root->val - 1]++;

    dfs(root->left);
    dfs(root->right);

    if (isLeaf(root)) {
      int odd_count = 0;
      for (auto count : visited) {
        odd_count += count % 2 != 0 ? 1 : 0;
      }

      if (odd_count <= 1)
        number++;
    }

    visited[root->val - 1]--;
  }

  int pseudoPalindromicPaths(TreeNode *root) {
    dfs(root);
    return number;
  }
};