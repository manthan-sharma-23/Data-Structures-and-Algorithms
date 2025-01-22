#include <algorithm>
#include <map>
#include <unordered_map>
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
    int Count = n;

    DisjointSet ds(n);

    vector<vector<int>> adj(n);

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    map<int, vector<int>> valueMap;
    vector<bool> isActive(n, false);

    for (int i = 0; i < n; i++) {
      int val = vals[i];
      valueMap[val].push_back(i);
    }

    for (auto [value_, nodes] : valueMap) {

      for (auto it : nodes) {
        for (auto v : adj[it]) {
          if (isActive[v]) {
            ds.unionBySize(it, v);
          }
        }
        isActive[it] = true;
      }

      unordered_map<int, int> leaders;

      for (auto i : nodes) {
        leaders[ds.findParent(i)]++;
      }

      for (auto [node, occurence] : leaders) {
        Count += (occurence * (occurence - 1) / 2);
      }
    }

    return Count;
  }
};