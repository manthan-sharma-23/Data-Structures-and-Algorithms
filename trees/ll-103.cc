#include <algorithm>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root)
      return {};
    vector<vector<int>> res;

    queue<TreeNode *> q;

    q.push(root);

    bool pass = 0;
    while (!q.empty()) {
      int size = q.size();
      vector<int> level;

      while (size--) {
        auto top = q.front();
        q.pop();

        if (top)
          level.push_back(top->val);

        if (top->left)
          q.push(top->left);

        if (top->right)
          q.push(top->right);
      }

      if (pass) {
        reverse(level.begin(), level.end());
      }
      pass = !pass;
      res.push_back(level);
      level.clear();
    }

    return res;
  }
};