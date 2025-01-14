#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

class Solution {
public:
  bool isValid(Node *root) {
    if (!root)
      return true;

    if (!root->left && !root->right)
      return true;

    int sum = 0;

    if (root->left) {
      sum += root->left->data;
    }
    if (root->right) {
      sum += root->right->data;
    }

    if (root->data != sum)
      return false;

    return isValid(root->left) && isValid(root->right);
  }

  int isSumProperty(Node *root) { return isValid(root); }
};