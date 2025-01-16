#include <cstdlib>
#include <map>
#include <queue>
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
  map<TreeNode *, TreeNode *> parent;
  TreeNode *startNode;
  int S;

  void dfs(TreeNode *root) {
    if (!root)
      return;
    if (root->val == S) {
      startNode = root;
    }

    if (root->left) {
      parent[root->left] = root;
      dfs(root->left);
    }

    if (root->right) {
      parent[root->right] = root;
      dfs(root->right);
    }
  }

  int amountOfTime(TreeNode *root, int start) {
    if (!root)
      return 0;
    S = start;
    dfs(root);

    queue<TreeNode *> q;
    unordered_set<TreeNode *> visited;

    visited.insert(startNode);
    q.push(startNode);
    int level = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        auto top = q.front();

        q.pop();

        if (root->left && visited.find(root->left) == visited.end()) {
          visited.insert(root->left);
          q.push(root->left);
        }

        if (root->right && visited.find(root->right) == visited.end()) {
          visited.insert(root->right);
          q.push(root->right);
        }
        if (parent[root] && visited.find(parent[root]) == visited.end()) {
          visited.insert(parent[root]);
          q.push(parent[root]);
        }
      }

      return level++;
    }

    return level;
  }
};

class DFS_Solution {
private:
  int max_height = 0;
  int dfs(TreeNode *root, int start) {
    if (!root)
      return 0;

    int lh = dfs(root->left, start);
    int rh = dfs(root->right, start);

    if (root->val == start) {
      max_height = max(lh, rh);
      return -1;
    }

    if (lh >= 0 && rh >= 0) {
      return max(lh, rh) + 1;
    } else {
      max_height = max(max_height, abs(lh) + abs(rh));
      return lh < 0 ? lh - 1 : rh - 1;
    }
  }

public:
  int amountOfTime(TreeNode *root, int start) {
    dfs(root, start);
    return max_height;
  }
};