#include <vector>

using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;

  bool isLeaf(Node *root) { return root && !root->left && !root->right; }

  void dfs(Node *root) {
    if (!root)
      return;

    path.push_back(root->data);
    if (isLeaf(root)) {
      res.push_back(path);
    } else {
      dfs(root->left);
      dfs(root->right);
    }
    path.pop_back();
  }

  vector<vector<int>> Paths(Node *root) {
    dfs(root);

    return res;
  }
};
