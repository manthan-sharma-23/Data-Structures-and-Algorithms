#include <set>
#include <unordered_set>
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
  vector<TreeNode *> ans;
  unordered_set<int> deletes;

  bool isLeaf(TreeNode *root) { return !root->left && !root->right; }

  TreeNode *dfs(TreeNode *root) {
    if (!root)
      return nullptr;

    root->left = dfs(root->left);
    root->right = dfs(root->right);

    if (deletes.find(root->val) != deletes.end()) {
      deletes.erase(root->val);
      if (root->left) {
        ans.push_back(root->left);
      }
      if (root->right) {
        ans.push_back(root->right);
      }
      delete root;
      return nullptr;
    }

    return root;
  }

  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    deletes.insert(to_delete.begin(), to_delete.end());

    if (deletes.find(root->val) == deletes.end()) {
      ans.push_back(root);
    }

    dfs(root);

    return ans;
  }
};