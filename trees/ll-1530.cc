#include <queue>
#include <unordered_map>
#include <unordered_set>
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
  int count = 0;

  vector<int> dfs(TreeNode *root, int distance) {
    if (!root)
      return {};

    auto leftV = dfs(root->left, distance);

    auto rightV = dfs(root->right, distance);

    if (!root->left && !root->right) {
      return {1};
    } else {
      for (auto ld : leftV) {
        for (auto rd : rightV) {
          if (ld + rd <= distance) {
            count++;
          }
        }
      }
      leftV.insert(leftV.end(), rightV.begin(), rightV.end());

      for (int i = 0; i < leftV.size(); i++)
        leftV[i]++;
      return leftV;
    }2
  }

  int countPairs(TreeNode *root, int distance) {
    dfs(root, distance);
    return count / 2;
  }
};