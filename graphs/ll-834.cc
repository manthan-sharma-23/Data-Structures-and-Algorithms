#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int N;
  unordered_map<int, int> countNodeInSubtrees;
  int rootTotalSum = 0;
  vector<vector<int>> adj;
  vector<int> result;

  int dfsIn(int u, int parent, int depth) {
    int totalNodes = 1;

    rootTotalSum += depth;

    for (auto node : adj[u]) {
      if (u == parent)
        continue;

      rootTotalSum += dfsIn(node, u, depth + 1);
    }
    countNodeInSubtrees[u] = totalNodes;
    return rootTotalSum;
  }

  void dfsOut(int u, int parent) {
    for (auto node : adj[u]) {

      if (node == parent)
        continue;

      result[node] = result[u] - countNodeInSubtrees[node] +
                     (N - countNodeInSubtrees[node]);

      dfsOut(node, u);
    }
  }

  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    this->N = n;
    adj.resize(n);
    result.resize(n, 0);

    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    rootTotalSum = 0;

    dfsIn(0, -1, 0);

    result[0] = rootTotalSum;

    vector<int> result(n, 0);
    result[0] = rootTotalSum;

    dfsOut(0, -1);

    return result;
  }
};