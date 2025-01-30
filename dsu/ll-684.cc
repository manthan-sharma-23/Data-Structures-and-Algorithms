#include <vector>

using namespace std;

class DisjointSet {
public:
  vector<int> parent, size;
  DisjointSet(int n) {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findParent(int n) {
    if (parent[n] == n)
      return n;

    return parent[n] = findParent(parent[n]);
  }

  void unionBySize(int u, int v) {
    int ult_u = findParent(u);
    int ult_v = findParent(v);

    if (ult_u == ult_v)
      return;

    if (size[ult_u] > size[ult_v]) {
      parent[ult_v] = ult_u;
      size[ult_u] += size[ult_v];
    } else {
      parent[ult_u] = ult_v;
      size[ult_v] += size[ult_u];
    }
  }
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();

    DisjointSet ds(n + 1);

    vector<int> missEdge = {};

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];

      if (ds.findParent(u) != ds.findParent(v)) {
        ds.unionBySize(u, v);
      } else {
        missEdge = edge;
      }
    }

    return missEdge;
  }
};