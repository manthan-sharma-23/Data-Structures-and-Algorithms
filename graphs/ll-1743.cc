#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> path;
  int N = 0;

  bool dfs(unordered_map<int, vector<int>> &adj, int u, int parent = 1e6) {
    path.push_back(u);

    if (path.size() == N) {
      return true;
    }

    for (auto node : adj[u]) {
      if (node == parent)
        continue;

      if (dfs(adj, node, u))
        return true;
    }

    path.pop_back();
    return false;
  }

  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    N = adjacentPairs.size() + 1;

    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> inDegree;

    // Populate the adjacency list and in-degree map
    for (auto &pair : adjacentPairs) {
      int u = pair[0];
      int v = pair[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
      inDegree[u]++;
      inDegree[v]++;
    }

    int start = 0;

    // Find the starting node (it will have an in-degree of 1)
    for (auto &entry : inDegree) {
      if (entry.second == 1) {
        start = entry.first;
        break;
      }
    }

    dfs(adj, start);

    return path;
  }
};
