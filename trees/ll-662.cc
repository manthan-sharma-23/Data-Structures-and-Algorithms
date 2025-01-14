#include <climits>
#include <map>
#include <queue>
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
  typedef long long int ll;

public:
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;

    queue<pair<TreeNode *, ll>> q;
    q.push({root, 0});
    ll max_width = 0;

    while (!q.empty()) {
      int size = q.size();
      ll first = q.front().second;
      ll last = q.back().second;
      max_width = max(max_width, last - first + 1);

      while (size--) {
        auto [node, index] = q.front();
        q.pop();

        ll normalized_index = index - first;

        if (node->left)
          q.push({node->left, 2 * normalized_index + 1});

        if (node->right)
          q.push({node->right, 2 * normalized_index + 2});
      }
    }

    return max_width;
  }
};
