#include "vector"

using namespace std;

class Solution {
public:
  bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int node,
           int parent) {
    visited[node] = true;

    for (auto &u : adj[node]) {
      if (u == parent) {
        continue;
      }

      if (visited[u])
        return true;

      if (dfs(adj, visited, u, node))
        return true;
    }

    return false;
  }

  bool isCycle(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++) {
      if (!visited[i] && dfs(adj, visited, i, -1)) {
        return true;
      }
    }

    return false;
  }
};