#include <vector>

using namespace std;

class DisjointSet {
  vector<int> parent, size;

public:
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

  bool unionBySize(int u, int v) {
    int ult_u = findParent(u);
    int ult_v = findParent(v);

    if (ult_u == ult_v)
      return false;

    if (size[ult_u] > size[ult_v]) {
      parent[ult_v] = ult_u;
      size[ult_u] += size[ult_v];
    } else {
      parent[ult_u] = ult_v;
      size[ult_v] += size[ult_u];
    }

    return true;
  }
};

class Solution {
public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1)
      return -1;

    DisjointSet ds(n);

    for (auto &connection : connections) {
      int x = connection[0];
      int y = connection[1];

      ds.unionBySize(x, y);
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
      if (ds.findParent(i) == i)
        components++;
    }
    return components - 1;
  }
};