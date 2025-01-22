#include <vector>

using namespace std;

class DisjointSet {
  vector<int> parent, size;
  int components;

public:
  DisjointSet(int n) {
    parent.resize(n);
    size.resize(n);
    components = n;

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
    components--;

    return true;
  }

  bool isSingle() { return components <= 1; }
};

class Solution {
public:
  vector<bool> areConnected(int n, int threshold,
                            vector<vector<int>> &queries) {

    DisjointSet ds(n + 1);

    for (int g = threshold + 1; g <= n; g++) {
      for (int multiple = 2 * g; multiple <= n; multiple += g) {
        ds.unionBySize(g, multiple);
      }
    }

    vector<bool> result;

    for (auto query : queries) {
      if (ds.findParent(query[0]) == ds.findParent(query[1])) {
        result.push_back(true);
      } else {
        result.push_back(false);
      }
    }

    return result;
  }
};