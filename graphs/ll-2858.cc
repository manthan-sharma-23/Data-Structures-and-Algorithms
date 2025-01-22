#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  struct Edge {
    int node;
    bool isReal;

    Edge(int node, bool isReal) : node(node), isReal(isReal) {}
  };

  vector<vector<Edge>> adj;
  vector<int> rootCount;

  int dfsIn(int u, int parent) {
    int count = 0;

    for (auto &edge : adj[u]) {
      if (edge.node == parent)
        continue;
      count += dfsIn(edge.node, u) + (edge.isReal == 0);
    }

    return count;
  }

  void dfsOut(int u, int parent, bool wasEdgeReal) {
    if (parent != -1) {
      int parentReversalCount = rootCount[parent];
      rootCount[u] = parentReversalCount + (wasEdgeReal ? 1 : -1);
    }

    for (auto &edge : adj[u]) {
      if (edge.node == parent)
        continue;
      dfsOut(edge.node, u, edge.isReal);
    }
  }

public:
  vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
    adj.resize(n);
    rootCount.resize(n, 0);

    for (auto edge : edges) {
      int u = edge[0];
      int v = edge[1];

      adj[u].emplace_back(Edge(v, true));
      adj[v].emplace_back(Edge(u, false));
    }

    rootCount[0] = dfsIn(0, -1);
    dfsOut(0, -1, true);

    return rootCount;
  }
};
