#include <algorithm>
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

struct Edge {
  int weight;
  int u;
  int v;

  Edge(int w, int src, int dest) : weight(w), u(src), v(dest) {}
};

class Solution {
public:
  int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<Edge> edges;

    for (int i = 0; i < V; i++) {
      for (auto &it : adj[i]) {
        int adjNode = it[0];
        int wt = it[1];
        int node = i;

        if (node < adjNode)
          edges.emplace_back(wt, node, adjNode);
      }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) { return a.weight < b.weight; });

    DisjointSet ds(V);
    int mstwt = 0;

    for (const auto &edge : edges) {
      if (ds.findParent(edge.u) != ds.findParent(edge.v)) {
        ds.unionBySize(edge.u, edge.v);
        mstwt += edge.weight;
      }
    }

    return mstwt;
  }
};
