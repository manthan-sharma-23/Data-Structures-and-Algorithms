#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool dfs(vector<vector<int>> &adj, vector<bool> &visited,
           vector<bool> &pathSum, int node) {
    visited[node] = true;
    pathSum[node] = true;
    for (auto &num : adj[node]) {
      if (!visited[num]) {
        if (dfs(adj, visited, pathSum, num))
          return true;
      } else if (pathSum[num]) {
        return true;
      }
    }
    pathSum[node] = false;
    return false;
  }

  bool isCyclic(int V, vector<vector<int>> adj) {
    vector<bool> visited(V, 0);
    vector<bool> pathSum(V, 0);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        if (dfs(adj, visited, pathSum, i))
          return true;
      }
    }

    return false;
  }
};