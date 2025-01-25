#include <cstddef>
#include <string>
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
  TreeNode *dfs(const string &traversal, int &index, int depth) {
    int currDepth = 0;
    while (index < traversal.length() && traversal[index] == '-') {
      currDepth++, index++;
    }

    if (currDepth != depth) {
      index -= currDepth;
      return nullptr;
    }

    int val = 0;
    while (index < traversal.size() && traversal[index] != '-')
      val = val * 10 + (traversal[index] - '0'), index++;

    TreeNode *node = new TreeNode(val);
    node->left = dfs(traversal, index, depth + 1);
    node->right = dfs(traversal, index, depth + 1);
    return node;
  }
  TreeNode *recoverFromPreorder(string traversal) {
    int index = 0;
    return dfs(traversal, index, 0);
  }
};