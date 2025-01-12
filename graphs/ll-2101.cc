#include "vector"
#include <cmath>

using namespace std;

class Solution {
public:
  int dfs(vector<vector<int>> &adj, vector<int> &visited, int u) {

    int count = 1;
    visited[u] = true;

    for (auto node : adj[u]) {
      if (!visited[node]) {
        count += dfs(adj, visited, node);
      }
    }

    return count;
  }

  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;

        long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
        long long x2 = bombs[j][0], y2 = bombs[j][1];

        long long distanceSquared =
            (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

        if (distanceSquared <= r1 * r1) {
          adj[i].push_back(j);
        }
      }
    }

    int maxBombs = 0;

    vector<int> visited(n, false);
    for (int i = 0; i < n; i++) {
      visited.clear();
      visited.resize(n, 0);

      maxBombs = max(maxBombs, dfs(adj, visited, i));
    }

    return maxBombs;
  }
};