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

  void populate_parents(TreeNode *root) {
    if (!root)
      return;

    if (root->left) {
      parent[root->left] = root;
      populate_parents(root->left);
    }

    if (root->right) {
      parent[root->right] = root;
      populate_parents(root->right);
    }
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    if (!root)
      return {};

    populate_parents(root);
    unordered_set<TreeNode *> visited;
    queue<TreeNode *> q;

    q.push(target);
    visited.insert(target);
    vector<int> ans;
    int level = 0;

    while (!q.empty()) {
      int size = q.size();

      if (level == k) {
        while (size--) {
          auto u = q.front();
          q.pop();
          ans.push_back(u->val);
        }
        return ans;
      }

      while (size--) {
        auto u = q.front();
        q.pop();

        if (parent[u] && visited.find(parent[u]) == visited.end()) {
          q.push(parent[u]);
          visited.insert(parent[u]);
        }

        if (u->left && visited.find(u->left) == visited.end()) {
          q.push(u->left);
          visited.insert(u->left);
        }

        if (u->right && visited.find(u->right) == visited.end()) {
          q.push(u->right);
          visited.insert(u->right);
        }
      }

      level++;
    }

    return ans;
  }
};