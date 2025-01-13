#include <queue>
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
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    if (root == nullptr)
      return {};

    vector<int> result;

    while (!q.empty()) {
      int size = q.size();
      TreeNode *node;
      while (size--) {
        auto *u = q.front();
        q.pop();
        node = u;

        if (u && u->left) {
          q.push(u->left);
        }
        if (u && u->right) {
          q.push(u->right);
        }
      }
      result.push_back(node->val);
    }

    return result;
  }
};

class DFS_Solution {

public:
  vector<int> result;
  void dfs(TreeNode *root, int level) {
    if (root == nullptr)
      return;

    if (result.size() < level) {
      result.push_back(root->val);
    }

    dfs(root->right, level + 1);
    dfs(root->left, level + 1);
  }

  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr)
      return {};

    dfs(root, 1);

    return result;
  }
};