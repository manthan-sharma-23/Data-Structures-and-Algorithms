#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int MIN = 1e5;
  vector<bool> visited;

  void dfs(vector<vector<pair<int, int>>> &adj, int u) {
    visited[u] = true;

    for (auto &node : adj[u]) {
      MIN = min(MIN, node.second);

      if (!visited[node.first]) {
        dfs(adj, node.first);
      }
    }
  }

  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> adj(n + 1);
    visited.resize(n + 1, false);

    for (auto road : roads) {
      int u = road[0];
      int v = road[1];
      int wt = road[2];

      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    dfs(adj, 1);

    return MIN;
  }
};
