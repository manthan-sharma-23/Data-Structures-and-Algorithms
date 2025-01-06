#include <set>
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
private:
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  bool isValid(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
  }

public:
  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();

    DisjointSet ds(n * n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0)
          continue;

        int nodeNo = (i)*n + (j);
        for (const auto &dir : directions) {
          int nrow = i + dir.first;
          int ncol = j + dir.second;

          if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
            int adjNodeNo = nrow * n + ncol;
            ds.unionBySize(nodeNo, adjNodeNo);
          }
        }
      }
    }
    int maxSize = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j])
          continue;
        set<int> components;
        for (const auto &dir : directions) {
          int nrow = i + dir.first;
          int ncol = j + dir.second;
          if (isValid(nrow, ncol, n) && grid[nrow][ncol]) {
            int newNodeNo = (nrow)*n + (ncol);
            components.insert(ds.findParent(newNodeNo));
          }
        }

        int size = 1;

        for (auto &it : components) {
          size += ds.size[it];
        }

        maxSize = max(size, maxSize);
      }
    }

    for (int cell = 0; cell < n * n; cell++) {
      maxSize = max(maxSize, ds.size[ds.findParent(cell)]);
    }

    return maxSize;
  }
};