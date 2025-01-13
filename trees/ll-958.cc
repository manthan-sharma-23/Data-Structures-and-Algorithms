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

class DFS_Solution {
private:
  int countNodes(TreeNode *node) {
    if (!node)
      return 0;

    return 1 + countNodes(node->left) + countNodes(node->right);
  }

  bool dfs(TreeNode *root, int index, int totalNodes) {
    if (!root)
      return true;

    if (index >= totalNodes)
      return false;

    return dfs(root->left, 2 * index + 1, totalNodes) &&
           dfs(root->right, 2 * index + 2, totalNodes);
  }

public:
  bool isCompleteTree(TreeNode *root) {
    if (root == nullptr)
      return true;

    int totalNodes = countNodes(root);

    return dfs(root, 0, totalNodes);
  }
};

class BFS_Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    if (root == nullptr)
      return true;

    queue<TreeNode *> q;
    q.push(root);
    bool past = false;
    while (!q.empty()) {
      auto top = q.front();
      q.pop();

      if (top && past)
        return false;

      if (!top) {
        past = true;
        continue;
      }

      q.push(top->left);
      q.push(top->right);
    }

    return true;
  }
};