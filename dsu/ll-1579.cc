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

    auto lambda = [&](vector<int> &v1, vector<int> &v2) {
      return v1[0] > v2[0];
    };

    sort(begin(edges), end(edges), lambda);
    DisjointSet Alice(n);
    DisjointSet Bob(n);

    int addedEdge = 0;

    for (auto &edge : edges) { // For each edge -
      int type = edge[0];
      int u = edge[1];
      int v = edge[2];

      if (type == 3) {
        bool add = false;

        if (Alice.findParent(u) != Alice.findParent(v)) {
          Alice.unionBySize(u, v);
          add = true;
        }

        if (Bob.findParent(u) != Bob.findParent(v)) {
          Bob.unionBySize(u, v);
          add = true;
        }

        if (add)
          addedEdge++;

      } else if (type == 2) {
        if (Bob.findParent(u) != Bob.findParent(v)) {
          Bob.unionBySize(u, v);
          addedEdge++;
        }
      } else {
        if (Alice.findParent(u) != Alice.findParent(v)) {
          Alice.unionBySize(u, v);
          addedEdge++;
        }
      }
    }

    if (Alice.isSingle() && Bob.isSingle()) {
      return edges.size() - addedEdge;
    }

    return -1;
  }
};