#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

class Solution {
private:
  map<Node *, Node *> parent;
  Node *targetNode;

  void findTargetAndFillParent(Node *root, int target) {
    if (!root)
      return;

    if (root->data == target)
      targetNode = root;

    if (root->left) {
      parent[root->left] = root;
      findTargetAndFillParent(root->left, target);
    }

    if (root->right) {
      parent[root->right] = root;
      findTargetAndFillParent(root->right, target);
    }
  }

public:
  int minTime(Node *root, int target) {

    if (!root)
      return 0;

    findTargetAndFillParent(root, target);

    if (!targetNode)
      return 0;

    unordered_set<Node *> visited;
    vector<int> ans;
    queue<Node *> q;

    q.push(targetNode);
    visited.insert(targetNode);

    int level = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        auto u = q.front();
        q.pop();

        if (parent[u] && visited.find(parent[u]) == visited.end()) {
          q.push(parent[u]);
          visited.insert(parent[u]);
        }

        if (u->left && visited.find(u->left) == visited.end()) {
          q.push(u->left);
          visited.insert(u->left);
        }

        if (u->right && visited.find(u->right) == visited.end()) {
          q.push(u->right);
          visited.insert(u->right);
        }
      }

      level++;
    }

    return level - 1;
  }
};