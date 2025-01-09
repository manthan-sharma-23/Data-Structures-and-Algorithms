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
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList,
                                         vector<vector<int>> &queries) {
    int n_query = queries.size();

    for (int i = 0; i < n_query; i++) {
      queries[i].push_back(i);
    }

    auto lambda = [&](vector<int> &a, vector<int> &b) { return a[2] < b[2]; };

    sort(edgeList.begin(), edgeList.end(), lambda);
    sort(queries.begin(), queries.end(), lambda);

    vector<bool> res(n_query, false);
    DisjointSet ds(n);
    int j = 0;
    for (const auto &query : queries) {

      int from = query[0];
      int to = query[1];
      int query_wt = query[2];
      int idx = query[3];

      while (j < edgeList.size() && edgeList[j][2] < query_wt) {
        ds.unionBySize(edgeList[j][0], edgeList[j][1]);
        j++;
      }

      if (ds.findParent(from) == ds.findParent(to))
        res[idx] = true;
      else
        res[idx] = false;
    }

    return res;
  }
};