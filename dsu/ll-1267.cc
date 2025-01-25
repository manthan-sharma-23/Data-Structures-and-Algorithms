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

  int maxSize() {
    int max_ = -1;
    for (int i = 0; i < size.size(); i++) {
      if (parent[i] == i) {
        max_ = max(max_, size[i]);
      }
    }

    return max_;
  }
};

class Solution {
public:
  int countServers(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    DisjointSet ds(m * n);

    for (int i = 0; i < m; i++) {
      int firstServer = -1;
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          if (firstServer != -1) {
            ds.unionBySize(i * n + firstServer, i * n + j);
          }
          firstServer = j;
        }
      }
    }

    for (int j = 0; j < n; j++) {
      int firstServer = -1;
      for (int i = 0; i < m; i++) {
        if (grid[i][j] == 1) {
          if (firstServer != -1) {
            ds.unionBySize(firstServer * n + j, i * n + j);
          }
          firstServer = i;
        }
      }
    }

    return ds.maxSize();
  }
};