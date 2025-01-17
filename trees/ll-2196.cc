#include <queue>
#include <set>
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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> mp;
    set<int> children;

    for (auto description : descriptions) {
      int parent = description[0];
      int child = description[1];
      bool isLeft = description[2];

      TreeNode *Parent = nullptr;
      if (mp.find(parent) == mp.end()) {
        Parent = new TreeNode(parent);
        mp[parent] = Parent;
      } else {
        Parent = mp[parent];
      }

      TreeNode *Child = nullptr;
      if (mp.find(child) == mp.end()) {
        Child = new TreeNode(child);
        mp[child] = Child;
      } else {
        Child = mp[child];
      }

      if (isLeft) {
        Parent->left = Child;
      } else {
        Parent->right = Child;
      }

      children.insert(child);
    }

    for (const auto &[key, node] : mp) {
      if (children.find(key) == children.end())
        return node;
    }

    return nullptr;
  }
};