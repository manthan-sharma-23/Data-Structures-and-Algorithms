#include <queue>
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
  vector<int> leftView(Node *root) {
    if (!root)
      return {};

    queue<Node *> q;
    q.push(root);

    vector<int> result;

    while (!q.empty()) {
      int size = q.size();
      Node *node = nullptr;
      while (size--) {
        auto top = q.front();
        q.pop();
        if (!node) {
          node = top;
        }

        if (top->left) {
          q.push(top->left);
        }
        if (top->right) {
          q.push(top->right);
        }
      }
      result.push_back(node->data);
    }

    return result;
  }
};