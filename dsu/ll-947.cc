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
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();

    DisjointSet ds(n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        else {
          if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
            ds.unionBySize(i, j);
          }
        }
      }
    }

    int components = 0;

    for (int i = 0; i < n; i++) {
      if (ds.findParent(i) == i)
        components++;
    }

    return n - components;
  }
};

class DFS_Solution {
private:
  void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node) {
    visited[node] = true;

    for (auto &u : adj[node]) {
      if (!visited[u]) {
        dfs(adj, visited, u);
      }
    }
  }

public:
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    vector<bool> visited(n, false);

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;

        auto stone1 = stones[i];
        auto stone2 = stones[j];

        if (stone1[0] == stone2[0] || stone1[1] == stone2[1]) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(adj, visited, i);
        components++;
      }
    }

    return n - components;
  }
};