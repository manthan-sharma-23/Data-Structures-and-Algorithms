#include <queue>

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
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;

    queue<TreeNode *> q;

    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int size = q.size();
      level++;

      while (size--) {
        auto top = q.front();
        q.pop();

        if (top->left) {
          q.push(top->left);
        }

        if (top->right) {
          q.push(top->right);
        }
      }
    }

    return level;
  }
};

class DFS_Solution {
public:
  int dfs(TreeNode *root) {
    if (!root)
      return 0;

    return max(dfs(root->left), dfs(root->right)) + 1;
  }

  int maxDepth(TreeNode *root) { return dfs(root); }
};