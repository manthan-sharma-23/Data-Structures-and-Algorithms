#include <algorithm>
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
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
    auto lambda = [&](vector<int> &a, vector<int> &b) { return a[2] > b[2]; };
    sort(edges.begin(), edges.end(), lambda);

    DisjointSet dsA(n);
    DisjointSet dsB(n);

    int used = 0;

    for (const auto edge : edges) {
      int type = edge[0];
      int from = edge[1] - 1;
      int to = edge[2] - 1;

      if (type == 3) {
        bool usedA = dsA.unionBySize(from, to);
        bool usedB = dsB.unionBySize(from, to);
        if (usedA || usedB)
          used++;
      } else if (type == 2) {
        if (dsB.findParent(from) != dsB.findParent(to)) {
          used++;
          dsB.unionBySize(from, to);
        }
      } else if (type == 1) {
        if (dsA.findParent(from) != dsA.findParent(to)) {
          used++;
          dsA.unionBySize(from, to);
        }
      }
    }

    return edges.size() - used;
  }
};