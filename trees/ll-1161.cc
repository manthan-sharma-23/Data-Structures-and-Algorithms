#include <climits>
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
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> q;

    q.push(root);

    int maxSum = INT_MIN, level = 0;
    int currLevel = 0;

    while (!q.empty()) {
      currLevel++;
      int size = q.size();

      int sum = 0;
      while (size--) {
        auto top = q.front();
        q.pop();

        sum += top->val;

        if (top->left)
          q.push(top->left);
        if (top->right)
          q.push(top->right);
      }

      if (sum >= maxSum) {
        maxSum = sum;
        level = currLevel;
      }
    }

    return level;
  }
};