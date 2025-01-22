#include "vector"
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
  vector<bool> friendRequests(int n, vector<vector<int>> &restrictions,
                              vector<vector<int>> &requests) {
    vector<bool> result;
    DisjointSet ds(n);

    for (auto &request : requests) {
      int a = request[0], b = request[1];

      int parent_a = ds.findParent(a), parent_b = ds.findParent(b);

      for (auto &restriction : restrictions) {
        int restricted_a = restriction[0], restricted_b = restriction[1];

        int pra = ds.findParent(restricted_a);
        int prb = ds.findParent(restricted_b);
        bool canMerge = true;

        if ((parent_a == pra && parent_b == prb) ||
            (parent_b == pra && parent_a == prb)) {
          canMerge = false;
        }

        if (!canMerge) {
          result.push_back(false);
        } else {
          ds.unionBySize(a, b);
          result.push_back(true);
        }
      }
    }

    return result;
  }
};
