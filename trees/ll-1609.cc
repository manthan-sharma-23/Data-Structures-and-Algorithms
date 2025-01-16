
#include <climits>
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
  bool isEven(int num) { return num % 2 == 0; }

  bool isEvenOddTree(TreeNode *root) {
    if (!root)
      return true;

    queue<TreeNode *> q;
    q.push(root);

    int level = 0;

    while (!q.empty()) {
      int size = q.size();
      bool isEvenLevel = isEven(level);

      int num_check = isEvenLevel ? INT_MIN : INT_MAX;

      while (size--) {
        TreeNode *u = q.front();
        q.pop();

        if (isEvenLevel) {
          if (isEven(u->val) || u->val <= num_check)
            return false;
        } else {
          if (!isEven(u->val) || u->val >= num_check)
            return false;
        }

        num_check = u->val;

        if (u->left)
          q.push(u->left);
        if (u->right)
          q.push(u->right);
      }
      level++;
    }

    return true;
  }
};
