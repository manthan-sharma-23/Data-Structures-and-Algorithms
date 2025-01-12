#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {

    vector<int> inDegree(n, 0);

    for (int i = 0; i < n; i++) {
      if (leftChild[i] != -1) {
        inDegree[leftChild[i]]++;
        if (inDegree[leftChild[i]] > 1)
          return false;
      }
      if (rightChild[i] != -1) {
        inDegree[rightChild[i]]++;
        if (inDegree[rightChild[i]] > 1)
          return false;
      }
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0) {
        if (root != -1)
          return false;
        root = i;
      }
    }

    if (root == -1)
      return false;

    queue<int> q;
    unordered_set<int> s;

    q.push(root);

    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      if (s.count(node))
        return false;

      s.insert(node);

      if (leftChild[node] != -1)
        q.push(leftChild[node]);
      if (rightChild[node] != -1)
        q.push(rightChild[node]);
    }

    return s.size() == n;
  }
};