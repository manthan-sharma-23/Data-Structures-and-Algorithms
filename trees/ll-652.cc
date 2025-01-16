#include <set>
#include <string>
#include <unordered_map>
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
  unordered_map<string, int> s;
  vector<TreeNode *> nodes;

  string serializeSubTrees(TreeNode *root) {
    if (!root)
      return "#";

    string left = serializeSubTrees(root->left);
    string right = serializeSubTrees(root->right);

    string hash = left + "," + right + ',' + to_string(root->val);

    if (s[hash] == 1) {
      nodes.push_back(root);
    }

    s[hash]++;
    return hash;
  }

  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    serializeSubTrees(root);
    return nodes;
  }
};