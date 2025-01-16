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
  vector<int> l1;
  vector<int> l2;

  bool isLeaf(TreeNode *node) { return !node->left && !node->right; }

  void dfs(TreeNode *root, bool _) {
    if (!root)
      return;

    dfs(root->left, _);
    dfs(root->right, _);

    if (isLeaf(root)) {
      if (_) {
        l1.push_back(root->val);
      } else {
        l2.push_back(root->val);
      }
    }
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    dfs(root1, true);
    dfs(root2, false);

    return l1 == l2;
  }
};