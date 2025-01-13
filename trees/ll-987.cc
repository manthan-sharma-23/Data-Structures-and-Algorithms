#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
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
  vector<vector<multiset<int>>> grid;

  int findHeight(TreeNode *root) {
    if (!root)
      return 0;

    return max(findHeight(root->left), findHeight(root->right)) + 1;
  }

  void dfs(TreeNode *root, int x, int y) {
    if (root) {
      grid[x][y].insert(root->val);
    }

    if (root->left)
      dfs(root->left, x + 1, y - 1);
    if (root->right)
      dfs(root->right, x + 1, y + 1);
  }

  vector<vector<int>> verticalTraversal(TreeNode *root) {
    if (!root)
      return {};

    int height = findHeight(root);
    int width = pow(2, height - 1);

    grid.resize(height + 2, (vector<multiset<int>>(width + 2)));

    dfs(root, 0, width / 2);

    vector<vector<int>> res;

    for (int j = 0; j < grid[0].size(); j++) {
      vector<int> col;
      for (int i = 0; i < grid.size(); i++) {
        if (grid[i][j].size() != 0) {
          for (auto num : grid[i][j]) {
            col.push_back(num);
          }
        }
      }
      if (col.size() != 0)
        res.push_back(col);
      col.clear();
    }

    return res;
  }
};
