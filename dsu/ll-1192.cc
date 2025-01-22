#include <vector>

using namespace std;

class DisjointSet {
  vector<int> parent, rank;
  int components;

public:
  DisjointSet(int n) {
    components = n;
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

      components--;
    }
  }

  bool isConnected() { return components == 1; }
};

class Solution {
public:
  pair<int, bool> mstWt(int n, vector<vector<int>> &connections,
                        vector<int> skippedConnection = {}) {
    DisjointSet ds(n);
    int mstWt = 0;

    for (auto &connection : connections) {
      if (connection == skippedConnection)
        continue;
      int u = connection[0], v = connection[1];

      if (ds.findParent(u) != ds.findParent(v)) {
        ds.union_set(u, v);
        mstWt++;
      }
    }

    return {mstWt, ds.isConnected()};
  }

  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    auto [bestMstWt, _] = mstWt(n, connections);
    vector<vector<int>> res;

    for (auto &connection : connections) {
      auto [newWt, isConnected] = mstWt(n, connections, connection);
      if (!isConnected) {
        res.push_back(connection);
      }
    }

    return connections;
  }
};