#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> adj;

  bool dfs(int node, const vector<vector<int>> &graph, vector<int> &color,
           int currentColor) {
    color[node] = currentColor;

    for (int neighbor : graph[node]) {
      if (color[neighbor] == -1) {
        if (!dfs(neighbor, graph, color, 1 - currentColor)) {
          return false;
        }
      } else if (color[neighbor] == color[node]) {
        return false;
      }
    }

    return true;
  }

  int dfs(int u, const vector<int> &height, vector<bool> &visited) {
    int maxHeight = height[u];
    visited[u] = true;

    for (auto node : adj[u]) {
      if (!visited[node]) {
        maxHeight = max(maxHeight, dfs(node, height, visited));
      }
    }

    return maxHeight;
  }

  bool isBipartite(vector<vector<int>> &graph, int n) {
    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++) {
      if (color[i] == -1) {
        if (!dfs(i, graph, color, 0)) {
          return false;
        }
      }
    }

    return true;
  }

  int bfs(int u, int n) {

    vector<bool> visited(n + 1, false);
    visited[u] = true;

    int height = 0;

    queue<int> q;

    q.push(u);

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int top = q.front();
        q.pop();

        for (auto node : adj[top]) {
          if (!visited[node]) {
            visited[node] = true;
            q.push(node);
          }
        }
      }

      height++;
    }

    return height;
  }

  int magnificentSets(int n, vector<vector<int>> &edges) {
    adj.resize(n + 1);

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    if (!isBipartite(adj, n))
      return -1;

    vector<int> heights(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      heights[i] = bfs(i, n);
    }

    int maxGroups = 0;

    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
      if (!visited[i])
        maxGroups += dfs(i, heights, visited);
    }

    return maxGroups;
  }
};