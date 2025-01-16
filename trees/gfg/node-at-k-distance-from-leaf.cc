#include <queue>
#include <set>
#include <unordered_map>
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
private:
  bool isLeaf(Node *node) { return !node->left && !node->right; }

  vector<Node *> path;
  set<Node *> nodes;

  void dfs(Node *root, int k) {
    if (!root)
      return;

    path.push_back(root);
    dfs(root->left, k);
    dfs(root->right, k);

    if (isLeaf(root)) {
      int idx = path.size() - k - 1;
      if (idx >= 0)
        nodes.insert(path[idx]);
    }

    path.pop_back();
  }

public:
  int printKDistantfromLeaf(Node *root, int k) {
    dfs(root, k);
    return nodes.size();
  }
};
