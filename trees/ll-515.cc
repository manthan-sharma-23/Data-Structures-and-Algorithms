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
  vector<int> largestValues(TreeNode *root) {

    queue<TreeNode *> q;

    q.push(root);
    int currLevel = 0;
    vector<int> ans;

    while (!q.empty()) {
      currLevel++;
      int size = q.size();

      int max_node = 0;
      while (size--) {
        auto top = q.front();
        q.pop();

        max_node = max(max_node, top->val);

        if (top->left)
          q.push(top->left);
        if (top->right)
          q.push(top->right);
      }

      ans.push_back(max_node);
    }

    return ans;
  }
};