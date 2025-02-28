#include <iostream>

using namespace std;

struct TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) : val(val) {}
};

int dfs(TreeNode *root) {

  if (!root)
    return 0;

  int leftAns = dfs(root->left);
  int rightAns = dfs(root->right);

  if (root->val == 1) {
    int ans = 0;

    if (root->left && root->left->val == 1 && root->right &&
        root->right->val == 1) {
      return rightAns + leftAns - 1;
    } else if ((root->left && root->left->val == 1) ||
               (root->right && root->right->val == 1)) {
      return leftAns + rightAns;
    } else {
      return leftAns + rightAns + 1;
    }

  } else {
    return leftAns + rightAns;
  }
}

int numIslands(TreeNode *root) { return dfs(root); }

int main() {
  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(0);
  root->left->left = new TreeNode(1);
  root->left->left->left = new TreeNode(0);
  root->left->left->left->left = new TreeNode(1);
  root->left->left->left->left->left = new TreeNode(1);
  root->left->left->left->left->right = new TreeNode(1);

  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);

  cout << numIslands(root) << endl;
}