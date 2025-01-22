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
  int minSwapsCouples(vector<int> &row) {
    int n = row.size() / 2;

    DisjointSet ds(n);

    for (int i = 0; i < row.size() - 1; i += 2) {
      int a = row[i] / 2;
      int b = row[i + 1] / 2;

      if (a != b) {
        ds.unionBySize(a, b);
      }
    }

    int components = 0;

    for (int i = 0; i < n; i++) {
      if (ds.findParent(i) == i) {
        components++;
      }
    }

    return n - components;
  }
};