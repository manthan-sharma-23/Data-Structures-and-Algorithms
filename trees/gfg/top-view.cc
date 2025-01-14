#include <map>
#include <set>
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
  map<int, pair<int, int>> grid;

  void dfs(Node *root, int x, int y) {
    if (!root)
      return;

    if (grid.find(x) == grid.end() || y < grid[x].first) {
      grid[x] = {y, root->data};
    }

    dfs(root->left, x - 1, y + 1);
    dfs(root->right, x + 1, y + 1);
  }

  vector<int> topView(Node *root) {
    if (!root)
      return {};

    dfs(root, 0, 0);

    vector<int> res;

    for (auto &P : grid) {

      res.push_back(P.second.second);
    }

    return res;
  }
};
