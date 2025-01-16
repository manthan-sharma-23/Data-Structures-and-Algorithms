#include <unordered_map>
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
  const int MOD = 1e9 + 7;
  unordered_map<TreeNode *, int> mp;

  int dfs(TreeNode *root) {

    if (!root)
      return 0;

    int leftSum = dfs(root->left);
    int rightSum = dfs(root->right);

    return mp[root] = (leftSum + rightSum + root->val) % MOD;
  }

  int maxProduct(TreeNode *root) {
    mp.clear();
    int tSum = dfs(root);

    long long maxProduct = 0;
    for (auto &[node, sum] : mp) {
      long long splitProduct = (long long)sum * (tSum - sum);
      maxProduct = max(maxProduct, splitProduct);
    }

    return maxProduct;
  }
};
