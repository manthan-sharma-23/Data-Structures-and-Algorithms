#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
  vector<int> rank, parent, size;

public:
  DisjointSet(int n) {
    rank.resize(n);
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

  void unionByRank(int u, int v) {
    int ult_u = findParent(u);
    int ult_v = findParent(v);

    if (ult_u == ult_v)
      return;

    if (rank[ult_v] > rank[ult_u]) {
      parent[ult_u] = ult_v;
    } else if (rank[ult_v] < rank[ult_u]) {
      parent[ult_v] = ult_u;
    } else {
      parent[ult_v] = ult_u;
      rank[ult_u]++;
    }
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

int main() {
  DisjointSet ds(7);

  ds.unionByRank(1, 2);
  ds.unionByRank(3, 2);
  ds.unionByRank(5, 6);
  ds.unionByRank(4, 6);

  cout << ds.findParent(4) << endl;
  return 0;
}