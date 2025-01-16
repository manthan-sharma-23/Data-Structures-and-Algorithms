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
  vector<vector<int>> res;
  vector<int> path;
  bool isLeaf(TreeNode *root) { return !root->left && !root->right; }

  void dfs(TreeNode *root, int target) {
    if (!root)
      return;
    path.push_back(root->val);

    if (isLeaf(root) && target == root->val) {
      res.push_back(path);
    } else {
      if (root->left)
        dfs(root->left, target - root->val);
      if (root->right)
        dfs(root->right, target - root->val);
    }
    path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (!root)
      return {};
    dfs(root, targetSum);
    return res;
  }
};