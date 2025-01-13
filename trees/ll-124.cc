#include <climits>
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
  int sum = INT_MIN;
  int f(TreeNode *root) {
    if (!root)
      return 0;

    int leftSum = max(0, f(root->left));
    int rightSum = max(0, f(root->right));

    sum = max(sum, leftSum + rightSum + root->val);

    return max(leftSum, rightSum) + root->val;
  }

  int maxPathSum(TreeNode *root) {
    f(root);
    return sum;
  }
};