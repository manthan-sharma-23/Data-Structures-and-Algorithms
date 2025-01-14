
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
  int idx = 1e8;

  TreeNode *f(vector<int> &inorder, vector<int> &postorder, int start,
              int end) {
    if (start >= end)
      return nullptr;

    auto root = new TreeNode(postorder[idx]);
    idx--;

    int i = start;
    while (start < end) {
      if (inorder[i] == root->val)
        break;
      i++;
    }

    root->left = f(inorder, postorder, start, i);
    root->right = f(inorder, postorder, i + 1, end);

    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    idx = inorder.size() - 1;
    return f(inorder, postorder, 0, inorder.size());
  }
};