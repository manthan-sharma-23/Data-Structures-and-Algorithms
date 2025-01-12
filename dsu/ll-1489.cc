#include <algorithm>
#include <vector>

using namespace std;

class DisjointSet {
  vector<int> parent, rank;

public:
  DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int findParent(int n) {
    if (parent[n] == n)
      return n;
    return parent[n] = findParent(parent[n]);
  }

  void union_set(int u, int v) {
    int ult_u = findParent(u);
    int ult_v = findParent(v);

    if (ult_u != ult_v) {
      if (rank[ult_u] < rank[ult_v]) {
        parent[ult_u] = ult_v;
      } else if (rank[ult_u] > rank[ult_v]) {
        parent[ult_v] = ult_u;
      } else {
        parent[ult_v] = ult_u;
        rank[ult_u]++;
      }
    }
  }
};

class Solution {
public:
  int kruskals(vector<vector<int>> &edges, int n, int skipped = -1,
               int add = -1) {
    DisjointSet ds(n);
    int mstWt = 0;

    if (add != -1) {
      ds.union_set(edges[add][0], edges[add][1]);
      mstWt += edges[add][2];
    }

    for (int i = 0; i < edges.size(); i++) {
      if (i == skipped)
        continue;

      const auto &edge = edges[i];
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];

      if (ds.findParent(u) != ds.findParent(v)) {
        ds.union_set(u, v);
        mstWt += wt;
      }
    }

    for (int i = 1; i < n; i++) {
      if (ds.findParent(0) != ds.findParent(i)) {
        return 1e7;
      }
    }

    return mstWt;
  }

  vector<vector<int>>
  findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
      edges[i].push_back(i);
    }

    sort(
        edges.begin(), edges.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });

    int bestMst = kruskals(edges, n);

    vector<vector<int>> res(2);

    for (int i = 0; i < edges.size(); i++) {
      if (kruskals(edges, n, i, -1) > bestMst) {
        res[0].push_back(edges[i][3]);
      } else if (kruskals(edges, n, -1, i) == bestMst) {
        res[1].push_back(edges[i][3]);
      }
    }

    return res;
  }
};
