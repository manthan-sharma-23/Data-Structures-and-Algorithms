#include <vector>
using namespace std;

class DisjointSet {
  vector<int> parent, size;

public:
  DisjointSet(int n) {
    parent.resize(n);
    size.resize(n, 1);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
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

  int size_(int u) { return size[findParent(u)]; }
};

class Solution {
public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    DisjointSet ds(n);

    for (const auto &edge : edges) {
      ds.unionBySize(edge[0], edge[1]);
    }

    long long total_pairs = (long long)n * (n - 1) / 2;
    long long reachable_pairs = 0;

    for (int i = 0; i < n; i++) {
      if (i == ds.findParent(i)) {
        long long size = ds.size_(i);
        reachable_pairs += size * (size - 1) / 2;
      }
    }

    return total_pairs - reachable_pairs;
  }
};
