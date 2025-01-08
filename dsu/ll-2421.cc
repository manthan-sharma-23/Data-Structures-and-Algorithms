#include <algorithm>
#include <map>
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
public:
  int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
    int n = vals.size();
    vector<vector<int>> adj(n);
    int result = n;

    DisjointSet ds(n);

    for (const auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    map<int, vector<int>> val_map;
    vector<bool> isActive(n, false);

    for (int i = 0; i < n; i++) {
      int value = vals[i];
      val_map[value].push_back(i);
    }

    for (const auto &[value, node] : val_map) {

      for (auto it : node) {
        for (auto child : adj[it]) {
          if (isActive[child]) {
            ds.unionBySize(it, child);
          }
        }
        isActive[it] = 1;
      }

      vector<int> leaders;
      for (auto i : node)
        leaders.push_back(ds.findParent(i));

      sort(leaders.begin(), leaders.end());

      int sz = leaders.size();

      for (int j = 0; j < sz; j++) {
        long long count = 0;
        int cur = leaders[j];

        while (j < sz && leaders[j] == cur)
          j++, count++;

        j--;

        result += count * (count - 1) / 2;
      }
    }

    return result;
  }
};