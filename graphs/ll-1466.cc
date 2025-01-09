#include "vector"
#include <queue>

using namespace std;

class Solution {
public:
  int count = 0;

  void dfs(vector<vector<pair<int, int>>> &adj, int u, int parent) {
    for (const auto pair : adj[u]) {
      if (pair.first != parent) {
        count += pair.second;
        dfs(adj, pair.first, u);
      }
    }
  }

  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<pair<int, int>>> adj(n);

    for (const auto &connection : connections) {
      int u = connection[0];
      int v = connection[1];

      adj[u].push_back({v, 1});
      adj[v].push_back({u, 0});
    }

    return count;
  }
};