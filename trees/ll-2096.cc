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
  int src, dest;
  string srcPath, destPath;
  void dfs(TreeNode *root, string &path) {
    if (!root)
      return;

    if (root->val == src) {
      srcPath.insert(srcPath.begin(), path.begin(), path.end());
    }
    if (root->val == dest) {
      destPath.insert(destPath.begin(), path.begin(), path.end());
    }

    path.push_back('L');
    dfs(root->left, path);
    path.pop_back();

    path.push_back('R');
    dfs(root->right, path);
    path.pop_back();
  }

  string getDirections(TreeNode *root, int startValue, int destValue) {
    src = startValue;
    dest = destValue;

    string path = "";
    dfs(root, path);

    int i = 0;
    while (srcPath[i] == destPath[i] &&
           (i == min(srcPath.length(), destPath.length()))) {
      srcPath.erase(i, 1);
      destPath.erase(i, 1);
    }

    for (int i = 0; i < srcPath.size(); i++) {
      srcPath[i] = 'U';
    }

    srcPath.insert(srcPath.end(), destPath.begin(), destPath.end());

    return srcPath;
  }
};